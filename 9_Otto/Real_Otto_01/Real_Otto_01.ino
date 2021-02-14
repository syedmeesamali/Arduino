#include<Servo.h>
#include <Otto9.h>
#include <US.h>
Otto9 Otto;  //This is Otto!
/*
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

//Main program setup
void setup() {
  Serial.begin(9600);
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);
}

//Main running loop of program
void loop() {
  servo1.write(30);
  delay(500);
  servo2.write(30);
  delay(500);
  servo3.write(30);
  delay(500);
  servo4.write(40);
  delay(1000);
}
*/

#define PIN_YL 5 //servo[0]  left leg
#define PIN_YR 4 //servo[1]  right leg
#define PIN_RL 3 //servo[2]  left foot
#define PIN_RR 2 //servo[3]  right foot
#define PIN_Trigger  8  //TRIGGER pin (8)
#define PIN_Echo     9  //ECHO pin (9)
#define PIN_Buzzer  13 //BUZZER pin (13)
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup(){
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, A6, PIN_Buzzer, PIN_Trigger, PIN_Echo); //Set the servo pins and ultrasonic pins and Buzzer pin
  Otto.sing(S_connection); //Otto wake up!
  Otto.home();
  delay(50);
}

void loop() { 
          Otto.walk(2,1000,1); //2 steps, "TIME". IF HIGHER THE VALUE THEN SLOWER (from 600 to 1400), 1 FORWARD
          Otto.walk(2,1000,-1); //2 steps, T, -1 BACKWARD 
          Otto.turn(2,1000,1);//3 steps turning LEFT
          Otto.turn(2,1000,-1);//3 steps turning LEFT
          Otto.home();
          delay(100);  
          Otto.turn(2,1000,-1);//3 steps turning RIGHT 
          Otto.bend (1,500,1); //usually steps =1, T=2000
          Otto.bend (1,2000,-1);     
          Otto.home();
          Otto.turn(5,1000,1);//6 steps turning LEFT
          Otto.turn(5,1000,-1);//3 steps turning LEFT
}
