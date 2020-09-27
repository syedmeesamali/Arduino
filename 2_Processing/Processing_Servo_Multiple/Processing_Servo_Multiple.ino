#include<Servo.h>
Servo servoFirst;
Servo servoSecond;

int val_1;
int val_2;
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
    val_1 = Serial.read();      //Read the value and store in val
  }
  if (val_1 == '1')
  {
    for (pos = 1; pos <= 45; pos++) {
        servoFirst.write(pos + 45);
        servoSecond.write(pos + 90);
        delay(100);
    }
  } else {
    for (pos = 0; pos <= 40; pos++) {
        servoFirst.write(pos);
        servoSecond.write(pos);
        delay(200);
    } for (pos = 40; pos > 0; pos--) {
        servoFirst.write(pos);
        servoSecond.write(pos);
        delay(200);
    }
  }
  delay(500);
}
