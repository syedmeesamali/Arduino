#include<Servo.h>   //Servo related code library

int led = 13;
Servo servo1;
int pos = 0;

void setup() {
  Serial.begin(57600);
  servo1.attach(8);
  servo1.write(0);
}

void loop() {
     while (Serial.available()) {
      delay(1);
      {
       if (Serial.read() == '1') {
        servo1.write(0);
      }  else if (Serial.read() == '2'){
        servo1.write(45);
      } else if (Serial.read() == '3'){
        servo1.write(90); 
      } else if (Serial.read() == '4'){
        servo1.write(135); 
      } else if (Serial.read() == '5'){
        servo1.write(180); 
      }  
   }//All within serial available      
 } //End of while loop
    
      
}//End of loop
