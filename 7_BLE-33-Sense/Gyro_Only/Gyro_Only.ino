#include <Arduino_LSM9DS1.h> //Include the library for 9-axis IMU

void setup(){
  Serial.begin(9600); //Serial monitor to display all sensor values 
  if (!IMU.begin()) //Initialize IMU sensor 
  { 
    Serial.println("Failed to initialize IMU!"); 
    while (1);
  }
 }

float gyro_x, gyro_y, gyro_z;

void loop()
{
  //Gyroscope values 
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gyro_x, gyro_y, gyro_z);
    //Serial.print("Gyroscope = %3.2f", gyro_x, gyro_y, gyro_z);
    Serial.print(gyro_x); Serial.print(", ");Serial.print(gyro_y);Serial.print("- ");Serial.print(gyro_z);Serial.print(";\n");
  }
  delay(1000);
}
