const int led = 13;
char incomingValue = 0;

void setup() {
  Serial.begin(9600);  // Debugging only
  pinMode(led, OUTPUT);
}

//Main loop of arduino
void loop() {
    if(Serial.available() > 0)
    {
      incomingValue = Serial.read();     //Value to be read from the serial port - if 1 turn ON else anything turn OFF
      Serial.print(incomingValue);
      Serial.print("\n");
      if (incomingValue == '1')
        digitalWrite(led, HIGH);
       else 
        digitalWrite(led, LOW);
    }
}
