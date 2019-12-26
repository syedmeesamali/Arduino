int trigPin = 11;       //Trigger pin
int echoPin = 12;       //Echo response pin
long duration, cm, inches;
const int buzzer = 8;

void playBuzzer() {   //This is buzzer playing routine
  pinMode (buzzer, OUTPUT);
  delay (50);
  analogWrite (buzzer, 0);
  delay (10);
  analogWrite (buzzer, 255);
  delay (50);
}

void setup() {   //Set the pin conditions
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void LED_Blink() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}

void loop() { //Main loop which will run forever
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
  if (inches < 3)  //Play buzzer and blink the built-in LED if distance less than 3 inches
  {
    playBuzzer();
    LED_Blink();
  }
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
}
