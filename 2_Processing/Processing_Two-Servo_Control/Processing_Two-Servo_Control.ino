#include<Servo.h>
Servo servoFirst;
Servo servoSecond;

int val;
int pos = 45;

void setup() {
  Serial.begin(9600);
  servoFirst.attach(9);     //Attach on pin # 9 of arduino
  servoFirst.write(45);      //Zero the inital position
  servoSecond.attach(8);      //Zero the inital position
  servoSecond.write(80);      //Zero the inital position
}


//Main running loop of program
void loop() {
  if (Serial.available()) 
  {
    val = Serial.read();      //Read the value and store in val
  }
  switch(val) {
      case '1':
        {
          servoFirst.write(90);
          delay(500);
          servoSecond.write(100);
          delay(500);
          servoFirst.write(30);
          servoSecond.write(20);  
        }
        break;
      case '2':
        {
          servoFirst.write(45);
          servoSecond.write(80);
          delay(200);  
        }
        break;
      case '3':
        {
          if (pos < 180) {
          pos = pos + 1;
          servoFirst.write(pos);
          delay(200);
          } else {
          pos = 180;
          servoFirst.write(pos);
          }  
        }
        break;
       case '4':
        {
          if (pos > 40) {
            pos = pos - 1;
            servoFirst.write(pos);
          delay(200);
          } else {
          pos = 40;
          servoFirst.write(pos);
          }
        }
        break;
      case '5':
        {
          if (pos < 180) {
          pos = pos + 1;
          servoSecond.write(pos);
          delay(200);
          } else {
          pos = 180;
          servoSecond.write(pos);
          }  
        }
        break;
       case '6':
        {
          if (pos > 40) {
            pos = pos - 1;
            servoSecond.write(pos);
          delay(200);
          } else {
          pos = 40;
          servoSecond.write(pos);
          }
        }
        break;
  
  } //End of switch case 
  
  delay(500);
}
