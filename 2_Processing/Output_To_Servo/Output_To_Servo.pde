import processing.serial.*;    //Include the serial object library
Serial myPort;
int serialVal = 0;

Button simple_stroke;
Button parkMotors;
Button increment_1;
Button decrement_1;
Button increment_2;
Button decrement_2;

//Main setup function
void setup() {
  printArray(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  print(portName);
  
  size(600,400);
  //background(40, 40, 40);
  frameRate(10);      //Canvas animation update frame-rate
  // create the button object
  simple_stroke = new Button("Simple Stroke", 20, 20, 150, 50);
  parkMotors = new Button("Park Motors", 20, 80, 150, 50);
  increment_1 = new Button("Increase Motor-1", 220, 20, 150, 40);
  decrement_1 = new Button("Decrease Motor-1", 220, 80, 150, 40);
  increment_2 = new Button("Increase Motor-2", 220, 140, 150, 40);
  decrement_2 = new Button("Decrease Motor-2", 220, 200, 150, 40);
}

//Main draw function to draw the buttons only
void draw() {
  simple_stroke.Draw();
  parkMotors.Draw();
  increment_1.Draw();
  decrement_1.Draw();
  increment_2.Draw();
  decrement_2.Draw();
}

// Mouse button clicked
void mousePressed()
{
  if (simple_stroke.MouseIsOver()) {
    myPort.write('1');
    println("Sent 1 to serial port!");
  } else if (parkMotors.MouseIsOver()) {
    myPort.write('2');
    println("Sent 2 to serial port!");
  } else if (increment_1.MouseIsOver()) {
    myPort.write('3');
    println("Sent 3 to serial port!");
  } else if (decrement_1.MouseIsOver()) {
    myPort.write('4');
    println("Sent 4 to serial port!");
  } else if (increment_2.MouseIsOver()) {
    myPort.write('5');
    println("Sent 5 to serial port!");
  } else if (decrement_2.MouseIsOver()) {
    myPort.write('6');
    println("Sent 6 to serial port!");
  } else {
    myPort.write('0');
  }
  
}

//MAIN BUTTON CLASS
class Button {
  String label;
  float x;
  float y;
  float w;
  float h;
  Button(String labelB, float xpos, float ypos, float width, float height) {
      label = labelB;
      x = xpos;
      y = ypos;
      w = width;
      h = height;
  }

  void Draw() {
    fill(218);
    stroke(141);
    rect(x, y, w, h, 10);
    textAlign(CENTER, CENTER);
    fill(0);
    text(label, x + (w / 2), y + (h / 2));
  }

  boolean MouseIsOver() {
    if (mouseX > x && mouseX < (x + w) && mouseY > y && mouseY < (y + h)){
      return true;
    } return false;
  }
}
