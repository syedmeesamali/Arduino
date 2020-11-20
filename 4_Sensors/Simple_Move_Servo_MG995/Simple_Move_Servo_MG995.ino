#include<Servo.h>
Servo servoFirst;
int pos = 0;
int VRx = A0;
int VRy = A1;
int SW = 2;
int xPosition = 0;
int yPosition = 0;

//Main program setup
void setup() {
  Serial.begin(9600);
  servoFirst.attach(8);     //Attach on pin # 8 of arduino
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}

//Main running loop of program
void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  pos = map(xPosition, 0, 1023, 0, 180);
  //pos = map(yPosition, 0, 1023, 0, 180);
  servoFirst.write(pos * 10);
  delay(100);
  /*for (pos = 0; pos < 2000; pos += 20)
  {
    servoFirst.write(pos);
    delay(100);
  }
  delay(300);*/
}
