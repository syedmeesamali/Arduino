#include<Servo.h>   //Servo related code library
Servo myServo;
int trigPin = 7;       //Trigger pin
int echoPin = 6;       //Echo response pin


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(8);
  myServo.write(0);       //Starting position as 0 angle
}

void loop() {
  int distance;
  for (int i=0; i<=180; i++) {
      digitalWrite(trigPin, HIGH);
      digitalWrite(trigPin, LOW);
      distance = pulseIn(echoPin, HIGH) / 50;
      Serial.print(i);
      Serial.print(":");
      Serial.print(distance);
      Serial.print(";");
      myServo.write(i);     //Sweep 0 to 180
      delay(50);
  }
  delay(1000);      //One second delay at end of movement
  for (int i=180; i>=0; i--) {
      digitalWrite(trigPin, HIGH);
      digitalWrite(trigPin, LOW);
      distance = pulseIn(echoPin, HIGH) / 50;
      Serial.print(i);
      Serial.print(":");
      Serial.print(distance);
      Serial.print(";");
      myServo.write(i);     //Sweep 0 to 180
      delay(50);
  }
  delay(1000);    //One second delay at end of movement
}
