#include<Servo.h>   //Servo related code library

int led = 13;
Servo servo1;
int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  servo1.attach(8);
  servo1.write(0);
}

void loop() {
      if (Serial.read() == '1') {
        digitalWrite(led, HIGH);
        servo1.write(0);
      }  else if (Serial.read() == '2'){
        digitalWrite(led, LOW);
        servo1.write(45);
      } else if (Serial.read() == '3'){
        digitalWrite(led, LOW);
        servo1.write(90); 
      } else if (Serial.read() == '4'){
        digitalWrite(led, HIGH);
        servo1.write(135); 
      } else if (Serial.read() == '5'){
        digitalWrite(led, HIGH);
        servo1.write(180); 
      }
}//End of loop
