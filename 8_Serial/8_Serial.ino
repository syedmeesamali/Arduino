int photo = 0;   //Analog input pin
int lightVal;

void setup() {
  pinMode(photo, INPUT);
  lightVal = analogRead(photo);
  Serial.begin(9600);  // Debugging only
}

//Main loop of arduino
void loop() {
    lightVal = analogRead(photo);
    Serial.print("Light value:");  
    Serial.println(lightVal);
}
