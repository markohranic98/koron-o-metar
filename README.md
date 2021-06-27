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
 
 
 #### Data collected
 * BLE scanner - number of nearby devices
 * PIR scanner - number of IR movement
 #### Data on monitor
 ![882a80de-1cd6-4520-835d-ee19fd9978e5](https://user-images.githubusercontent.com/76110238/122641630-e2cc9780-d106-11eb-9924-188fa4b3c2c2.jpg)

 #### Cloud data example-
 ![output example](https://user-images.githubusercontent.com/76110238/122640455-06401400-d100-11eb-835b-f7a27251e0b8.png)
 #### Device
 ![62995630-3cda-47c3-be3b-a4dfc183fcbe](https://user-images.githubusercontent.com/76110238/122641644-f2e47700-d106-11eb-8ae3-4a43e127d2b3.jpg) 
#### Showcase video https://youtu.be/ydYZvq5M6qM
#### Credits:
* Davor Cihlar - mentor , Embedded Linux Software Engineer at INTIS
* Doc. dr. sc. Boris Tomaš - mentor, professor
* Marko Hranić - student
* Karla Franović - student
* Domagoj Sitar - student
* Andreja Trivić - student
* Klara Lupoglavac - student
