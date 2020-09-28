#include<Servo.h>
Servo servoFirst;
Servo servoSecond;

int val;
int pos = 0;

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
    val = Serial.read();      //Read the value and store in val
  }
  if (val == '1')
  {
    for (pos = 1; pos <= 45; pos++) {
        servoFirst.write(pos);
        servoSecond.write(pos);
        delay(100);
    }
    } else if (val == '2') {
    for (pos = 45; pos <= 90; pos++) {
        servoFirst.write(pos);
        servoSecond.write(pos);
        delay(100);
    } 
    } else if (val == '3') {
    for (pos = 90; pos <= 135; pos++) {
        servoFirst.write(pos);
        servoSecond.write(pos);
        delay(100);
      } 
    } else if (val == '4') {
    for (pos = 135; pos <= 180; pos++) {
        servoFirst.write(pos);
        servoSecond.write(pos);
        delay(100);
        } 
    } else if (val == '0'){
        servoFirst.write(pos--);
        servoSecond.write(pos--);
        delay(500);
    } 
  delay(500);
}
