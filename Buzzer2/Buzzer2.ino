const int pinRef = 12;

void setup () {
  pinMode(pinRef, OUTPUT);
}


void loop () {
  digitalWrite(pinRef, HIGH);
  delay(1000);
  digitalWrite(pinRef, LOW);
  delay(200);
}
