# TC74 BRZO

ESP8266 library for the I2C controlled TC74 temperature sensor.

This library uses the BRZO I2C library for the ESP8266.
[https://github.com/pasko-zh/brzo_i2c](https://github.com/pasko-zh/brzo_i2c)


This library also supports the TC74 Standby mode.
In this mode the A/D converter is halted and the temperature data registers are frozen.
On power up the TC74 enters Standby Mode.
In Standby mode the power consumption is 5 µA (in normal mode 200 μA)

###TC74 Info
- Power supply range of 2.7V to 5.5V.
- Temperature range of -65°C to +127°C.
- Temperature resolution is 1°C.
- I2C Clock Frequency 100kHz.
- Normal and Standby mode.

###TC74 Addresses
  - A0	0x48
  - A1	0x49
  - A2	0x4A
  - A3	0x4B
  - A4	0x4C
  - A5	0x4D //Default
  - A6	0x4E
  - A7	0x4F
  
###Driver API
**TC74_BRZO tc74(address)**
Init the temperature sensor with the given address.

**temp(int8_t)**
Read the temperature as int8_t. Returns the brzo_i2c error code.
Brzo_i2c error codes see [README](https://github.com/pasko-zh/brzo_i2c/blob/master/README.md)

**standby()**
Set the standby mode. In this mode the A/D converter is halted and the temperature data registers are frozen.
Returns the brzo_i2c error code.

**on()**
Set the normal mode. Returns the brzo_i2c error code.



Created for Arduino IDE and PlatformIO.


This library is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

