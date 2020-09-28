import processing.serial.*;    //Include the serial object library
Serial myPort;
int serialVal = 0;
Button deg_45;
Button deg_90;
Button deg_135;
Button deg_180;
int clk = 1;


//Main setup function
void setup() {
  printArray(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  print(portName);
  
  size(800,600);
  //background(40, 40, 40);
  frameRate(10);      //Canvas animation update frame-rate
  // create the button object
  deg_45 = new Button("45 Degrees", 20, 20, 100, 50);
  deg_90 = new Button("90 Degrees", 20, 80, 100, 50);
  deg_135 = new Button("135 Degrees", 20, 140, 100, 50);
  deg_180 = new Button("180 Degrees", 20, 200, 100, 50);
}

//Main draw function
void draw() {
  
  deg_45.Draw();
  deg_90.Draw();
  deg_135.Draw();
  deg_180.Draw();
  
}

// Mouse button clicked
void mousePressed()
{
  if (deg_45.MouseIsOver()) {
    // print some text to the console pane if the button is clicked
    myPort.write('1');
    println("Sent 1 to serial port!");
  } else if (deg_90.MouseIsOver()) {
    myPort.write('2');
    println("Sent 2 to serial port!");
  } else if (deg_135.MouseIsOver()) {
    myPort.write('3');
    println("Sent 3 to serial port!");
  } else if (deg_180.MouseIsOver()) {
    myPort.write('4');
    println("Sent 4 to serial port!");
  } else {
    myPort.write('0');
    println("Sent 0 to serial port!");
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
