#include<Servo.h>
Servo servoFirst;
Servo servoSecond;

int trigPin = 7;       //Trigger pin
int echoPin = 6;       //Echo response pin
long duration, cm, inches;

void setup() {
  Serial.begin(9600);
  servoFirst.attach(8);     //Attach on pin # 8 of arduino
  servoFirst.write(60);      //Initial position of first motor
  servoSecond.attach(10);      //Attach second motor on pin # 10 of arduino
  servoSecond.write(80);      //Initial position of second motor
  pinMode(trigPin, OUTPUT);   //Trigger pin to throw the signal sound waves
  pinMode(echoPin, INPUT);    //Echo pin for input of distance
}

//Main running loop of program
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;       //Formula to calculate distance in inches
  
  if (inches < 4) {         //If distance is less than 4 inches then make stroke
      servoFirst.write(130);      //Position of bat (second motor)
      servoSecond.write(130);     //Position of base
      delay(300);
      servoFirst.write(70);       //Bring to lower side to strike
      servoSecond.write(30);      //Rotate CW for strike
  }
  delay(300);
}
