
/*
    MicroOLED ------------- Photon
      GND ------------------- GND
      VDD ------------------- 3.3V 
    D1/MOSI ----------------- A5 
    D0/SCK ------------------ A3 
      D2
      D/C ------------------- D6 
      RST ------------------- D7 
      CS  ------------------- A2
      
      
      PIR--------------------Photon
      + --------------------5V
      GND-------------------GND
      Alarm-----------------D5
      
      ESP-WROOM-32----------Photon
      GND--------------------GND
      5V---------------------5V
      22---------------------SCL
      21---------------------SCK
      
      ESP-WROOM-32 is on LOLIN32 v1.0.0. board
      
      Code collects data from PIR sensor and ESP32 Bluetooth scan and publishes it on
      particle console and showcases it on Sparkfun Micro OLED. Time between publish and OLED
      refresh is set to 30 seconds
*/



#include "SparkFunMicroOLED.h"  
#include <Wire.h>

MicroOLED oled;

int pirPin = D5; //sets the pir pin to D5
int x = 0; //this will be used as number of bluetooth devices
int y = 0; // number PIR activations 
long int wait=30000; //dalay of loop


void receiveEvent(int bytes) { 
  x = Wire.read();    //gets the x value from ESP-32 using I2C
}


void oledOutput() 
{
    oled.clear(PAGE);            
    oled.setCursor(0, 0);        
    oled.setFontType(0);         
    oled.print("BLE:");          
    oled.setFontType(0);         
    oled.print(x);  
    oled.setCursor(0, 16);       
    oled.setFontType(0);         
    oled.print("PIR:");
    oled.setFontType(0);
    oled.print(y);
    oled.print("/30");
    oled.display();       
}



void setup()
{
  Serial.begin(9600);
  //start the OLED
  oled.begin();    
  oled.clear(ALL); 
  oled.display();
  //starts PIR
  pinMode(pirPin, INPUT_PULLUP); 
  //establishes I2C communication 
  Wire.begin(23);
  Wire.onReceive(receiveEvent);
}

void loop()
{
  y = 0; // reset the value of y to 0 
  int loopTime = 0; 
  int pirValState;
  while(loopTime<(wait/1000)){
      pirValState = digitalRead(pirPin); //read the value from PIR
      if(pirValState==LOW){ // if there was movement
          y++; //increment y
          loopTime++;
          delay(1000);
      }
      else { //else just wait
          loopTime++;
          delay(1000);
      }
  }
  Particle.publish(String(x),String(y)); //publish  values on particle console
  oledOutput();
}



