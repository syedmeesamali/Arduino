#include<Servo.h>
Servo servoFirst;
Servo servoSecond;
int pos = 0;        //Position relaed variable
int val = 0;        //Value to be received on the serial port


//Main program setup
void setup() {
  Serial.begin(9600);
  servoFirst.attach(8);     //Attach on pin # 8 of arduino
  servoFirst.write(0);      //Initial position of first motor
  servoSecond.attach(10);      //Attach second motor on pin # 10 of arduino
  servoSecond.write(20);      //Initial position of second motor
}

//Function to make simple most steps
void MoveStep() 
{
  servoFirst.write(50);
  delay(300);
  servoSecond.write(20);
  delay(300);
}


//Main running loop of program
void loop() {

  if (Serial.available()) 
  {
    val = Serial.read();      //Read the value and store in val
  }
  
  switch(val) 
  {
      case '1':                 //Make a stroke with robotic arm from top left to bottom right in a good speed
        {
              servoFirst.write(20);      //Increase is CCW
              delay(300);
              servoSecond.write(0);     //DECREASE is CCW
              delay(300);
              servoFirst.write(20);     //Increase is CCW
              delay(300);
              servoSecond.write(0);     //DECREASE is CCW
          }
        break;
      
      case '2':               //Park the robot at 0
        {
          servoFirst.write(0);
          servoSecond.write(0);
          delay(500);  
        }
        break;
  } //End of switch case 
  
  delay(300);
}
