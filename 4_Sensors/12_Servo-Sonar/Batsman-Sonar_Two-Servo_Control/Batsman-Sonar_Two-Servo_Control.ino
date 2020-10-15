#include<Servo.h>
Servo servoFirst;
Servo servoSecond;
int trigPin = 7;       //Trigger pin
int echoPin = 6;       //Echo response pin
long duration, cm, inches;

int val;
int pos = 45;

void setup() {
  Serial.begin(9600);
  servoFirst.attach(8);     //Attach on pin # 9 of arduino
  servoFirst.write(60);      //Zero the inital position
  servoSecond.attach(10);      //Zero the inital position
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
  
  if (inches < 4) {         //Read the distance less than 2cm and then make stroke else not
      servoFirst.write(130);      //Position of main bat
      servoSecond.write(130);     //Position of base
      delay(300);
      servoFirst.write(70);       //Bring to lower side to strike
      servoSecond.write(30);      //Rotate to right side for strike
  }
  delay(30dn0);
}
