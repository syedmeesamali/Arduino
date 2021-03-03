#include<Servo.h>
Servo base;           //Servo motor for the base
Servo lower_arm;           //Servo motor for the base
Servo main_arm;           //Servo motor for the base
Servo gripper;           //Servo motor for the base
int val;

//Main program setup
void setup() {
  Serial.begin(9600);
  gripper.attach(8);     //Attach on pin # 8 of arduino
  base.attach(10);     //Attach on pin # 8 of arduino
  lower_arm.attach(7);     //Attach on pin # 8 of arduino
  main_arm.attach(9);     //Attach on pin # 8 of arduino
  gripper.write(100);
}

//Main running loop of program
void loop() {
  if (Serial.available()) 
  {
    val = Serial.read();      //Read the value and store in val
  }
  switch(val) {
      case '1':                 //Grab the object
        {   gripper.write(180);     }   break;
      case '2':                 //Release the gripper
        {   gripper.write(120);     }   break;
  } 
}
