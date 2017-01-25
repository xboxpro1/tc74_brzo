/*
  tc74_i2c_brzo.h - ESP8266 I2C library for TC74 temperature sensor.  
  This library uses the BRZO_I2C library for the ESP8266.
  
  Created Jan 2017
  By Martin Stahl	https://github.com/xboxpro1/tc74_i2c_brzo

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
  TC74 Address
  A0	0x48
  A1	0x49
  A2	0x4A
  A3	0x4B
  A4	0x4C
  A5	0x4D // This is the default address
  A6	0x4E
  A7	0x4F
  
  
  TC74 SCL frequency 100kHz
*/

#ifndef tc74_i2c_brzo_h
#define tc74_i2c_brzo_h

#include <stdint.h>
#include "brzo_i2c.h"

class TC74_I2C_BRZO {
	
public:
  TC74_I2C_BRZO(uint8_t TC74_Addr);

  uint8_t readtemp(int8_t *t);
  uint8_t powersave(void);
  uint8_t nopowersave(void);
  

private:
  uint8_t _Addr;
};

#endif
