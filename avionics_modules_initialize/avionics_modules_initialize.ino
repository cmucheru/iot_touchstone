//17th Mar 2022
//Objectives: To initialize esp32 mcu, bmp180, gps module a mpu6050 module.


#include <Wire.h> //For communication over I2C
#include "i2cdev.h"
#include <MPU6050.h>
#include <SFE_BMP180.h> //For bmp 180 lib
#include <Arduino_MKRGPS.h> //For gps lib
#include "i2c_scanner.h" //To scan the module

//Initializing esp32 for WiFi Connections
//void initDone() {
// wifi_set_opmode_current(STATION_MODE);
// struct station_config stationConfig;
// strncpy(stationConfig.ssid, "myssid", 32);
// strncpy(stationConfig.password, "mypassword", 64);
// wifi_station_set_config(&stationConfig);
//}

//For mpu6050
MPU6050 mpu6050;

void setup() 
{
  Wire.begin();     
  Serial.begin(9600);        
  delay(1500);  
  mpu6050.initialize();  
  delay(2); 
}

//For BMP 180
void setup() {
  Serial.begin(9600);
  bool success = bmp180.begin();

  if (success) {
    Serial.println("BMP180 init success");
  }
}

//For GPS module
void setup(){
  GPS.begin(GPS_MODE_I2C);
   if (!GPS.begin()) {
    Serial.println("Failed to initialize GPS!");
    while (1);
  }
}
