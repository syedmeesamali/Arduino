#include<Servo.h>   //Servo related code library

char in_value = 0;    //Value received via bluetooth
Servo servo1;         //Servo-1 initialization
int val;

void setup() {
  Serial.begin(9600);
  servo1.attach(8);       //Attach servo-1 at pin # 8 of arduino
  servo1.write(0);
}

void loop() {
   if (Serial.available() > 0) {
      in_value = Serial.read();
      Serial.print(in_value + "\n");
      if (in_value == '1')
      {
        servo1.write(45);
      } else if (in_value == '0') {
        servo1.write(90);
      }
   }
}//End of loop

/*void serialEvent() {
  val = Serial.parseInt();
  if (val != 0) {
    servo1.write(val);
  }
}*/
