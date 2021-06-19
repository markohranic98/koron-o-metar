/*
 * Program for ESP-WROOM-32 LOLIN32 V1.0.0 module that scans for nearby 
 * bluetooth devices every *waitMs* then sends it to Photon redboard through I2C using SDA lane
 */

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <Wire.h> //I2C module

int waitMs =1000; // time should be set to an interval that is less than Particle.publish();

BLEScan* pBLEScan;
int deviceCount = 0;

void setup() { //
  Serial.begin(115200); // can be left out, we have it here for testing purposes
  Wire.begin(); //initializes I2C communication
  BLEDevice::init("Koron-o-metar"); // name can be left blank, we have it on for testing purposes
}

void loop() {
  pBLEScan = BLEDevice::getScan(); 
  pBLEScan->setActiveScan(true);  // true(active scan) consumes more energy
  BLEScanResults foundDevices = pBLEScan->start(1); //starts the scan
  deviceCount = foundDevices.getCount(); //gets the number of devices
  Serial.println(deviceCount); //Serial print used for testing purposes
  Wire.beginTransmission(23);  //begins I2C transmission on designited adress
  //adress can be found using i2c_scanner code, source code is attached in folder
  //original code on https://playground.arduino.cc/Main/I2cScanner/
  Wire.write(deviceCount);     //writes data
  Wire.endTransmission();      //ends transmision
  pBLEScan->clearResults();  //free memory
  delay(waitMs); //delay untill next scan
}
