import serial
import time

startMarker = '<'
endMarker = '>'
dataStarted = False
dataBuf = ""

messageComplete = False

def SetupSerial(baudRate, serialPortName):
    global serialPort
    serialPort = serial.Serial(port = serialPortName, baudRate = baudRate, timeout = True, rtscts = True)
    print("Serial port: " + serialPortName + " opened at BaudRate: " + str(baudRate))
    waitForArduino()

def sendToArduino(stringToSend):
    global startMarker, endMarker, serialPort
    stringWithMarkers = (startMarker)
    stringWithMarkers += stringToSend
    stringWithMarkers += (endMarker)
    serialPort.write(stringWithMarkers.encode('utf-8'))

def rcvLikeArduino():
    global startMarker, endMarker, serialPort, dataStarted, dataBuf, messageComplete
    if serialPort.inWaiting() > 0 and messageComplete == False:
        x = serialPort.read().decode('utf-8')       #Decode needed
        if dataStarted == True:
            if x != endMarker:
                dataBuf = dataBuf + x
            else:
                dataStarted = False
                messageComplete = True
        elif x == startMarker:
            dataBuf = ''
            dataStarted = True
    
    if (messageComplete == True):
        messageComplete = False
        return dataBuf
    else:
        return "XXX"

def waitForArduino():
    #Wait until arduino sends "Arduino is ready"
    #Any bytes left from previous messages are discarded
    print("Waiting for Arduino to reset!")
    msg = ""
    while msg.find("Arduino is ready") == -1:
        msg = rcvLikeArduino()
        if not (msg == 'XXX'):
            print(msg)

SetupSerial(11500, "dev/ttyACM0")
count = 0
prevTime = time.time()
while True:
    arduinoReply = rcvLikeArduino()
    if not (arduinoReply == 'XXX'):
        print("Time %s reply %s" %(time.time(), arduinoReply))
    if time.time() - prevTime > 1.0:
        sendToArduino("this is a test " + str(count))
        prevTime = time.time()
        count += 1