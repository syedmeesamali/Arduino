int sensorVal = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(sensorVal);
  Serial.println(value);
  delay(500);       //200ms delay before next value
}//End of loop
