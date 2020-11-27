import processing.serial.*;

Serial myPort;
String val;
float angle;
float distance;
String data = "";
int index = 0;
int xpos = 100;
int ypos = 100;

//Main setup code
void setup()
{
  size(400, 400);
  String portName = Serial.list()[0];    //Main serial port name
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil(';');
  background(255, 255, 255);
}

//Main draw function
void draw()
{
  fill(255, 0, 0);
  noStroke();
  ellipse(xpos, ypos, 10, 10);
} //End of draw

void SerialEvent(Serial myPort)
{
  val = myPort.readStringUntil('\n');
}
