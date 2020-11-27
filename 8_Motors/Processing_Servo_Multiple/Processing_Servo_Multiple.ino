#include<Servo.h>
Servo servoFirst;
Servo servoSecond;

int val;
int pos = 0;

void setup() {
  Serial.begin(9600);
  servoFirst.attach(9);     //Attach on pin # 9 of arduino
  servoFirst.write(45);      //Zero the inital position
  servoSecond.attach(8);      //Zero the inital position
  servoSecond.write(45);      //Zero the inital position
}


//Main running loop of program
void loop() {
  if (Serial.available()) 
  {
    val = Serial.read();      //Read the value and store in val
  }
  if (val == '1')
    {
    for (pos = 75; pos >= 25; pos--) {
        servoFirst.write(pos);
        servoSecond.write(pos);
        delay(100);
        }
    } else if (val == '0'){
        servoFirst.write(45);
        servoSecond.write(45);
        delay(200);
    } else if (val == '5'){
        pos = pos + 1;
        servoFirst.write(pos);
        delay(200);
    } else if (val == '6'){
        pos = pos - 1;
        servoFirst.write(pos);
        delay(200);
    } else if (val == '7'){
        pos = pos + 1;
        servoSecond.write(pos);
        delay(200);
    } else if (val == '8'){
        pos = pos - 1;
        servoSecond.write(pos);
        delay(200);
    } 
  delay(500);
}
