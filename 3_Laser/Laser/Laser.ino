//Example code KY012 active buzzer
int laser = 12;
void setup () {
  pinMode (laser, OUTPUT);
}
void loop () {
  digitalWrite(laser, HIGH);
  delay (100);
  digitalWrite(laser, LOW);
  delay (100);
}
