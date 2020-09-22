int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
      if (Serial.read() == '1') {
        digitalWrite(led, HIGH);
        Serial.println("LED is ON");
      }  else if (Serial.read() == '0'){
        digitalWrite(led, LOW);
        Serial.println("LED is OFF");
      } //End of if
}//End of loop
