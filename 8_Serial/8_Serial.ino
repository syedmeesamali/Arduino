int photo = 0;   //Analog input pin
int lightVal;

void setup() {
  pinMode(photo, INPUT);
  Serial.begin(9600);  // Debugging only
}

//Main loop of arduino
void loop() {
    lightVal = analogRead(photo);
    Serial.println(lightVal);
    delay(500);
}
