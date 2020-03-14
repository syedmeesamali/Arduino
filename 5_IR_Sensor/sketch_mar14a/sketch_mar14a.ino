#include<IRremote.h>

int IRSensor = 2;
int LED = 13;

IRrecv irrecv(IRSensor); //IR receive object
decode_results decodedSignal; //Store results from detector

void setup () {
  pinMode (IRSensor, OUTPUT);
  //Serial.begin(9600);
  irrecv.enableIRIn();
}

boolean lightState = false;
unsigned long last = millis();

void loop () {
  if (irrecv.decode(&decodedSignal) == true)
  
  {
    Serial.println(decodedSignal.value, HEX);
    if (millis() - last > 250){
      lightState = !lightState;
      digitalWrite(LED, lightState);
    }
    last = millis();
    irrecv.resume();
  }
    
}
