#include<Servo.h>
Servo servoFirst;

//Main program setup
void setup() {
  Serial.begin(9600);
  servoFirst.attach(8);     //Attach on pin # 8 of arduino
}

//Main running loop of program
void loop() {
  servoFirst.write(0);
  delay(1500);
  servoFirst.write(90);
  delay(1500);
  servoFirst.write(180);
  delay(1500);
  servoFirst.write(90);
  delay(1500);
}
