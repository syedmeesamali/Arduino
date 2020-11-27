#include<Servo.h>
Servo servoFirst;
int pos_x = 0;
int pos_y = 0;
int VRx = A0;
int VRy = A1;
int SW = 2;
int xPosition = 0;
int yPosition = 0;

//Main program setup
void setup() {
  Serial.begin(9600);
  servoFirst.attach(8);     //Attach on pin # 8 of arduino
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}

//Main running loop of program
void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  pos_x = map(xPosition, 0, 1023, -180, 180);
  pos_y = map(yPosition, 0, 1023, -180, 180);
  Serial.print(pos_x);Serial.print(",");
  Serial.print(pos_y);Serial.print(";\n");
  servoFirst.write(pos_x * 10);
  delay(200);
}
