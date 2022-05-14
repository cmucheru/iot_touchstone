#include <Wire.h> //For communication over I2C
#include "i2cdev.h"
#include <MPU6050.h>
#include <SFE_BMP180.h> //For bmp 180 lib
#include <Arduino_MKRGPS.h> //For gps lib
#include "i2c_scanner.h" //To scan the module

void initializeComponents();

//Initializing esp32 for WiFi Connections
//void initDone() {
// wifi_set_opmode_current(STATION_MODE);
// struct station_config stationConfig;
// strncpy(stationConfig.ssid, "myssid", 32);
// strncpy(stationConfig.password, "mypassword", 64);
// wifi_station_set_config(&stationConfig);
//}

void initializeComponents(){
Serial.begin(115200);  
Wire.begin();   
  
//MPU6050 init
  Serial.println("Accelerometer Check...");
  if(!accelerometer.begin()){
    Serial.println("Accelerometer not found...");
    while (1) {
      delay(2000);
    }
  }
  
  Serial.println("Accelerometer OK...");

//BMP180 init
void setup() {
  bool success = bmp180.begin();
    if (success) {
    Serial.println("BMP180 initialization success ...");
  }
}
//GPS module init
void setup(){
  GPS.begin(GPS_MODE_I2C);
   if (!GPS.begin()) {
    Serial.println("Failed to initialize GPS!");
    while (1);
  }
 }
}
