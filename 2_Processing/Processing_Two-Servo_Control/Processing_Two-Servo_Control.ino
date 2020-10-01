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
      case '1':                 //Make a stroke with robotic arm from top left to bottom right in a good speed
        {
          servoFirst.write(100);
          delay(300);
          servoSecond.write(140);
          delay(300);
          servoFirst.write(30);
          servoSecond.write(70);  
        }
        break;
      case '2':               //STOP the motors at particular position
        {
          servoFirst.write(45);
          servoSecond.write(80);
          delay(200);  
        }
        break;
      case '3':             //Increase position of Motor - 1
        {
          if (pos < 180) {
          pos = pos + 5;
          servoFirst.write(pos);
          delay(200);
          } else {
          pos = 180;
          servoFirst.write(pos);
          }  
        }
        break;
       case '4':          //Decrease position of Motor - 1
        {
          if (pos > 40) {
            pos = pos - 5;
            servoFirst.write(pos);
          delay(200);
          } else {
          pos = 40;
          servoFirst.write(pos);
          }
        }
        break;
      case '5':       //Increase position of Motor - 2
        {
          if (pos < 180) {
          pos = pos + 5;
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
          if (pos > 70) {     //Decrease position of Motor - 2
            pos = pos - 5;
            servoSecond.write(pos);
          delay(200);
          } else {
          pos = 60;
          servoSecond.write(pos);
          }
        }
        break;
  
  } //End of switch case 
  
  delay(300);
}
