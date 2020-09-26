import processing.serial.*;    //Include the serial object library
Serial myPort;
int serialVal = 0;

//Main setup function
void setup() {
  printArray(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  print(portName);
  
  size(1000,1000);
  background(40, 40, 40);
  frameRate(10);      //Canvas animation update frame-rate
}

//Main draw function
void draw() {
  background(40, 40, 40);
  fill(255, 255, 255);
  if (myPort.available() > 0)
  {
    String val;
    val = myPort.readStringUntil('\n');
    println(val);
    ellipse(200, 200, parseFloat(val)/2, parseFloat(val)/2);
  } 
}
