#include<Servo.h>   //Servo related code library
int led = 13;
Servo servo1;
int val;

void setup() {
  Serial.begin(9600);
  servo1.attach(8);
  servo1.write(0);
}

void loop() {
      
}//End of loop

void serialEvent() {
  val = Serial.parseInt();
  if (val != 0) {
    servo1.write(val);
  }
}
