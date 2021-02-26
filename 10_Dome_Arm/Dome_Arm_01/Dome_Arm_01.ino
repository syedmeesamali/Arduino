#include<Servo.h>
Servo base;           //Servo motor for the base
Servo lower_arm;           //Servo motor for the base
Servo main_arm;           //Servo motor for the base
Servo gripper;           //Servo motor for the base

//Main program setup
void setup() {
  Serial.begin(9600);
  gripper.attach(8);     //Attach on pin # 8 of arduino
  base.attach(10);     //Attach on pin # 8 of arduino
  lower_arm.attach(7);     //Attach on pin # 8 of arduino
  main_arm.attach(9);     //Attach on pin # 8 of arduino
}

//Main running loop of program
void loop() {
  for (int i=60; i <= 120; i = i + 5)
  {
    gripper.write(i);
    delay(500);
  }
  delay(1500);
  for (int j = 120; j >= 60; j = j - 5)
  {
    gripper.write(j);
    delay(200);
  }
  delay(1500);
}
