//Example code KY012 active buzzer
int laser = 12;
void setup () {
  pinMode (laser, OUTPUT);
}
void loop () {
  digitalWrite(laser, HIGH);
  delay (200);
  digitalWrite(laser, LOW);
  delay (5000);
  digitalWrite(laser, HIGH);
  delay (200);
}
