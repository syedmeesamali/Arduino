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
  gripper.write(120);
  delay(1000);
  gripper.write(180);
  delay(5000);
  
}
