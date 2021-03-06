import processing.serial.*;
Serial myPort;

String val;
float x_val;
float y_val;
float z_val;
String data = "";
int index1 = 0;
int index2 = 0;
float xpos = 100;
float ypos = 100;

//Main setup code
void setup()
{
  size(400, 400);
  String portName = Serial.list()[0];    //Main serial port name
  print("Serial port is: ", portName);
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil(';');
  background(255, 255, 255);    //White back-ground
}

//Main draw function
void draw()
{
  fill(255, 0, 0);      //Red color
  noStroke();
  ellipse(xpos, ypos, 10, 10);
} //End of draw

//serialEvent should be with a SMALL 's' and not CAPITAL 'S'
void serialEvent(Serial myPort)
{ 
  { //Main procedure for reading the values for x and y
    data = myPort.readStringUntil(';');
    data = data.substring(0, data.length() - 1);
    index1 = data.indexOf(',');
    x_val = float(data.substring(0, index1));
    y_val = float(data.substring(index1 + 1, data.length()));
    print("X_val: ", x_val);
    print("Y_val: ", y_val);
    xpos = 100 + x_val;
    ypos = 100 + y_val;
  } 
}
