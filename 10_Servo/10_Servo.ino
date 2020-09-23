#include<Servo.h>   //Servo related code library

int led = 13;
Servo servo1;
int pos = 0;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  servo1.attach(8);
  servo1.write(180);
}

void loop() {
      if (Serial.read() == '1') {
        digitalWrite(led, HIGH);
        Serial.println("LED is ON");
        servo1.write(90);
      }  else if (Serial.read() == '0'){
        digitalWrite(led, LOW);
        Serial.println("LED is OFF");
        servo1.write(0);
      } //End of if
}//End of loop
