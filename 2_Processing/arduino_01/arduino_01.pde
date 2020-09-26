import processing.serial.*;    //Include the serial object library
Serial myPort;
int serialVal = 0;

//Main setup function
void setup() {
  myPort = new Serial(this, Serial.list()[0], 9600);
  
  size(800,800);
  background(40, 40, 40);
  frameRate(10);      //Canvas animation update frame-rate
}

//Main draw function
void draw() {
  background(40, 40, 40);
  fill(255, 255, 255);
  ellipse(500, 500, serialVal, serialVal);
}

//READING THE SERIAL MESSAGES FROM ARDUINO
String buf = "";
int lf = 10;

void SerialEvent(Serial p) {
  int c = myPort.read();  
  serialVal = int(buf);
  if (c == lf) {
    serialVal = int(buf);
    buf = "";
  } 
}
