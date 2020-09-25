#define inputCLK 4
#define inputDT 5

#define laser 8
int counter = 0;
int currentStateCLK;
int prevStateCLK;

String encdir = "";

void setup () {

  pinMode(inputCLK, INPUT);
  pinMode(inputDT, INPUT);
  pinMode(laser, OUTPUT);

  Serial.begin(9600);
  prevStateCLK = digitalRead(inputCLK); //Read the previous state of pin
  
} //End of SETUP

void loop () {
    currentStateCLK = digitalRead(inputCLK);
    if (currentStateCLK != prevStateCLK) {
      if (digitalRead(inputDT) != currentStateCLK) {
      counter--;      //Decrement the counter
      encdir = "CCW";
      digitalWrite(laser, LOW);
    } else {
      counter++;      //Decrement the counter
      encdir = "CW";
      digitalWrite(laser, HIGH);
    } 
    Serial.print("Direction: ");
    Serial.print(encdir);
    Serial.print(" -- Value: ");
    Serial.println(counter);
    }
    prevStateCLK = currentStateCLK;
}//End of LOOP
