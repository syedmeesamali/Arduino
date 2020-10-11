#include<Servo.h>   //Servo related code library
Servo myServo;


void setup() {
  Serial.begin(9600);
  myServo.attach(8);
  myServo.write(0);       //Starting position as 0 angle
}

void loop() {
  for (int i=0; i<=180; i++) {
      myServo.write(i);     //Sweep 0 to 180
      delay(50);
  }
  delay(3000);
  for (int i=180; i>=0; i--) {
      myServo.write(i);   //Sweep 180 to 0
      delay(50);
  }
  delay(3000);
}
