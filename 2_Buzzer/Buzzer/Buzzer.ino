//Example code KY012 active buzzer
int speakerPin = 8;
void setup () {
  pinMode (speakerPin, OUTPUT);
}
void loop () {
  analogWrite (speakerPin, 125);
  delay (50);
  analogWrite (speakerPin, 0);
  delay (10);
  analogWrite (speakerPin, 255);
  delay (40);
}
