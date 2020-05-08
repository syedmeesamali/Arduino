int Laser = 2; // creating a variable named Laser and assigning it to digital pin 2
void setup()
{

pinMode (Laser,OUTPUT); // designating pin 2 as output (we can use "Laser" instead of the pin # because we assigned "Laser" to pin 2 above)
digitalWrite(Laser,LOW); // making sure the laser is off at startup or reset
}

void loop() 
{

digitalWrite(Laser,HIGH); // turning the laser on
delay(100); // waiting for 1/4 of a second
digitalWrite(Laser,LOW); // turning the laser off
delay(1000); // waiting for 1/4 of a second

}
