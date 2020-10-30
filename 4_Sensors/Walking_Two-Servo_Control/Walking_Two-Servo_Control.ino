#include<Servo.h>
Servo servoFirst;
Servo servoSecond;
int pos = 0;        //Position relaed variable
int val = 0;        //Value to be received on the serial port

void setup() {
  Serial.begin(9600);
  servoFirst.attach(8);     //Attach on pin # 8 of arduino
  servoFirst.write(0);      //Initial position of first motor
  servoSecond.attach(10);      //Attach second motor on pin # 10 of arduino
  servoSecond.write(20);      //Initial position of second motor
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
              servoFirst.write(10);      //Increase is CCW
              servoSecond.write(0);      //Increase is CCW
              delay(300);
              servoFirst.write(0);
              servoSecond.write(10);     //DECREASE is CCW
              delay(300);
              servoFirst.write(20);
              servoSecond.write(0);     //DECREASE is CCW
              delay(300);
          }
        break;
      //------------New case----------
      case '2':               //Park the robot at 0
        {
          servoFirst.write(0);
          servoSecond.write(0);
          delay(500);  
        }
        break;
      //------------New case----------
      case '3':             //Increase position of Motor - 1
        {
          if (pos <= 100) {
          pos = pos + 10;
          servoFirst.write(pos);
          delay(200);
          } else {
          pos = 100;
          servoFirst.write(pos);
          }
        }
        break;
       //------------New case----------
       case '4':          //Decrease position of Motor - 1
        {
          if (pos >= 100) {
            pos = pos - 5;
            servoFirst.write(pos);
          delay(200);
          } else {
          pos = 0;
          servoFirst.write(pos);
          }
        }
        break;
      //------------New case----------
      case '5':       //Increase position of Motor - 2
        {
          if (pos <= 100) {
          pos = pos + 5;
          servoSecond.write(pos);
          delay(200);
          } else {
          pos = 100;
          servoSecond.write(pos);
          }  
        }
        break;
       //------------New case----------
       case '6':
        {
          if (pos >= 100) {     //Decrease position of Motor - 2
            pos = pos - 5;
            servoSecond.write(pos);
          delay(200);
          } else {
          pos = 0;
          servoSecond.write(pos);
          }
        }
        break;
  } //End of switch case 
  delay(300);
}   //End of main program loop
