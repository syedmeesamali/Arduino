import processing.serial.*;
Serial myPort;

String val;
float x_val;
float y_val;
float z_val;
String data = "";
int index1 = 0;
int index2 = 0;
int xpos = 100;
int ypos = 100;
int zpos = 20;

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
  fill(255, 0, zpos);      //Red color
  noStroke();
  ellipse(xpos, ypos, 10, 10);
} //End of draw

void serialEvent(Serial myPort)
{
  data = myPort.readStringUntil(';');
  if (data != null)
  {
    float[] list = float(splitTokens(data, ","));
    x_val = list[0];
    y_val = list[1];
    z_val = list[2];
    print("list: ", list);
    print("X_val: ", x_val);
    print("Y_val: ", y_val);
    print("Z_val: ", list[2]);
    print("\n");
    xpos = 100 + int(x_val)*2;
    ypos = 100 + int(y_val)*2;
    zpos = 100 + int(z_val)*2;
    redraw();
  }
}
