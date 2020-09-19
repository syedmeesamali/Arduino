import processing.serial.*;    //Include the serial object library

Serial mySerial;
String myString = null;    //Variable to collect the serial data

//Main setup function
void setup() {
  size(600,600);
  mySerial = new Serial(this, "COM3", 9600);
  mySerial.bufferUntil("\n");
}

//Main draw function
void draw() {
}
