int sensorPin = A0;
int ledPin = 13;
int sensorVal = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(sensorVal);
  digitalWrite(ledPin, LOW);
  delay(sensorVal);
  Serial.println(sensorVal, DEC);
}
