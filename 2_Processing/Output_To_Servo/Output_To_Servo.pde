import processing.serial.*;    //Include the serial object library
Serial myPort;
int serialVal = 0;
Button on_button;
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
  on_button = new Button("Click Me", 20, 20, 100, 50);
}

//Main draw function
void draw() {
  if (on_button.MouseIsOver()) {
    rect(50, 20, 50, 50);
  }
  else {
    // hide the square if the mouse cursor is not over the button
    background(0);
  }
  // draw the button in the window
  on_button.Draw();
  if (mousePressed == true) {
      println("1");
      myPort.write('1');
  } else {
      println("0");
      myPort.write('0');
  }
}

// mouse button clicked
void mousePressed()
{
  if (on_button.MouseIsOver()) {
    // print some text to the console pane if the button is clicked
    print("Clicked: ");
    println(clk++);
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
