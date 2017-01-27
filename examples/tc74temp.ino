/*
tc74temp.ino
Example for Microchip TC74 temperature sensor using the TC74_I2C_BRZO library
The sketch reads the TC74 sensor via BRZO_I2C and outputs the data to the serial port

Created Jan 2017
By Martin S		https://github.com/xboxpro1/tc74_i2c_brzo
*/

#include <Arduino.h>	// need for PlatformIO
#include "tc74_i2c_brzo.h"

#define I2CSDA      4                           //brzo SDA Pin
#define I2CSCL      5                           //brzo SCL Pin
#define SCLSTRECH   5000                        //brzo SCL Stretch timeout

TC74_I2C_BRZO tc74(0x4D);                       // set the TC74 address to 0x4D (default) see tc74_i2c_brzo.h

int8_t temperature;                             // Define variable to hold the temperature
uint8_t errorcode;
bool  initok = false;

void setup(){
   brzo_i2c_setup(I2CSDA, I2CSCL, SCLSTRECH);   // Initialize the brzo_i2c library
   Serial.begin(115200);                        // Initialize the serial port
   delay(1000);
   Serial.print ("Set the TC74 Sensor in normal mode.... ");	
   errorcode = tc74.on();              // Set the TC74 sensor in normal mode, on Startup the TC74 enters Standby Mode.
   if(errorcode == 0) then {
     Serial.println ("OK");
     initok = true;
   }
  else {
     Serial.println ("ERROR!!!");
     Serial.print ("Error Code: ");
     Serial.println (errorcode);
     Serial.println ("Please reset device!");
  }
 }


void loop(){
    if(initok){
      errorcode = tc74.temp(temperature);
      if(errorcode == 0){
        Serial.print ("Temperature: ");
        Serial.print (temperature);
        Serial.println (" C");
      }
       else{
         Serial.println ("ERROR!!!");
         Serial.print ("Error Code: ");
         Serial.println (errorcode);
       }
       
      delay(5000);					// Wait 5 seconds
    }
}
