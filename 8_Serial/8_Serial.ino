const int led = 8;
int ledState = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);  // Debugging only
}

//Main loop of arduino
void loop() {
    char receiveVal;
    if(Serial.available() > 0)
    {
      receiveVal = Serial.read();     //Value to be read from the serial port - if 1 turn ON else anything turn OFF
      if (receiveVal == '1')
        ledState = 1;
       else 
        ledState = 0;
    }
    digitalWrite(led, ledState);      //Update the LED value
}
