#include<Servo.h>
Servo base;           //Servo motor for the base

//Main program setup
void setup() {
  Serial.begin(9600);
  base.attach(8);     //Attach on pin # 8 of arduino
}

//Main running loop of program
void loop() {
  for (int i=0; i <= 180; i = i + 5)
  {
    base.write(i);
    delay(200);
  }
  delay(1500);
  for (int j = 180; j > 0; j = j - 5)
  {
    base.write(j);
    delay(200);
  }
  delay(2000);
}
