#include<Servo.h>
Servo servoFirst;
Servo servoSecond;

int val_1;
int val_2;

void setup() {
  Serial.begin(9600);
  servoFirst.attach(9);     //Attach on pin # 9 of arduino
  servoFirst.write(0);      //Zero the inital position
  servoSecond.attach(8);      //Zero the inital position
  servoSecond.write(0);      //Zero the inital position
}


//Main running loop of program
void loop() {
  if (Serial.available()) 
  {
    val_1 = Serial.read();      //Read the value and store in val
  }
  if (val_1 == '1')
  {
    servoFirst.write(45);
    servoSecond.write(90);
  } else {
    servoFirst.write(90);
    servoSecond.write(180);
  }
  delay(50);
}
