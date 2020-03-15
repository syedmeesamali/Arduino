#include<IRremote.h>

const int IR_Recv = 2;
const int laser = 8;
int LED = 13;

IRrecv irrecv(IR_Recv); //IR receive object
decode_results decodedSignal; //Store results from detector

void setup () {
  pinMode (laser, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

//boolean lightState = false;
//unsigned long last = millis();

void loop () {
  if (irrecv.decode(&decodedSignal))
  {
    Serial.println(decodedSignal.value, HEX);
    switch(decodedSignal.value)
    {
      case 0xFD20DF:
          Serial.println("Button 4 pressed! Laser ON");
          digitalWrite(laser, LOW); //Makes it ON
    }

    switch(decodedSignal.value)
    {
    case 0xFDA05F:
          Serial.println("Button 5 pressed ! Laser OFF");
          digitalWrite(laser, HIGH); //High makes it OFF
    }
    irrecv.resume();
  }
    
}
