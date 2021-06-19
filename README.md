# koron-o-metar
arduino/sparkfun device that collects PIR and BLE scan data to determine crowd intensity in an area

### Requirements
 ####  Hardware:
  1. Sparkfun Photon Redboard https://www.sparkfun.com/products/13321
  1. About 15 jumper wires
  1. Breadboard
  1. Power supply - we used USB
  1. SparkFun Micro OLED https://www.sparkfun.com/products/13003
  1. PIR Motion Sensor https://www.sparkfun.com/products/13285
  1. ESP-WROOM-32 LOLIN32 v1.0.0. or any ESP32 module
#### Software:

  1. Arduino IDE
  2. Particle console/ Web IDE
    
    
 ### Wiring guide:
    '''
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
          
      '''
      
 #### Wiring example- WARNING - USE GUIDE ABOVE
 ![Start Simulating](https://user-images.githubusercontent.com/76110238/122606330-1234c300-d079-11eb-97d0-16c0170ef097.png)
      
#### Credits:
* Davor Cihlar - mentor , Embedded Linux Software Engineer at INTIS
* Doc. dr. sc. Boris Tomaš - mentor, professor
* Marko Hranić - student
* Karla Franović - student
* Domagoj Sitar - student
* Andreja Trivić - student
* Klara Lupoglavac - student
