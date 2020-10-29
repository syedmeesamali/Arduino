#include<Servo.h>
Servo servoFirst;
Servo servoSecond;
int pos = 0;        //Position relaed variable
void setup() {
  Serial.begin(9600);
  servoFirst.attach(8);     //Attach on pin # 8 of arduino
  servoFirst.write(0);      //Initial position of first motor
  servoSecond.attach(10);      //Attach second motor on pin # 10 of arduino
  servoSecond.write(0);      //Initial position of second motor
}

//Main running loop of program
void loop() {
  /*
  servoFirst.write(30);
  delay(500);
  servoSecond.write(30);
  delay(500);
  servoFirst.write(0);
  delay(500);
  servoSecond.write(0);
  delay(500);   */
}
