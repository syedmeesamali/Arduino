#include<Servo.h>
Servo servoFirst;
Servo servoSecond;
int trigPin = 11;       //Trigger pin
int echoPin = 12;       //Echo response pin
long duration, cm, inches;

int val;
int pos = 45;

void setup() {
  Serial.begin(9600);
  servoFirst.attach(9);     //Attach on pin # 9 of arduino
  servoFirst.write(45);      //Zero the inital position
  servoSecond.attach(8);      //Zero the inital position
  servoSecond.write(80);      //Zero the inital position
  pinMode(trigPin, OUTPUT);   //Trigger pin to throw the signal sound waves
  pinMode(echoPin, INPUT);    //Echo pin for input of distance
}


//Main running loop of program
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
  
  if (Serial.available()) 
  {
    val = Serial.read();      //Read the value and store in val
  }
  switch(val) {
      case '1':                 //Make a stroke with robotic arm from top left to bottom right in a good speed
        {
          if (inches < 2) {         //Read the distance less than 2cm and then make stroke else not
              servoFirst.write(100);
              delay(300);
              servoSecond.write(140);
              delay(300);
              servoFirst.write(30);
              servoSecond.write(70);  
          }
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
