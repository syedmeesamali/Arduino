#include<Servo.h>
Servo servoFirst;
int val;

void setup() {
  Serial.begin(9600);
  servoFirst.attach(9);     //Attach on pin # 9 of arduino
  servoFirst.write(0);      //Zero the inital position
}

void loop() {
  if (Serial.available()) 
  {
    val = Serial.read();      //Read the value and store in val    
  }
  if (val == '1')
  {
    servoFirst.write(90);
  } else {
    servoFirst.write(180);
  }
  delay(50);
}
