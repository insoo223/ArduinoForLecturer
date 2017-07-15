/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : EEPROMRead.ino
  Author  : Insoo Kim (insoo@hotmail.com)
  Date    : Dec 12, 2014
  Update  : Mon Aug 10, 2015
            Sat Jul 15, 2017 - Put more comments to lecture 
  Desc    : 
    1) Reads the value of each byte of the EEPROM and prints it to the serial monitor.

    2) Use <EEPROM.h> library. 
    Works with all LCD displays that are compatible with the Hitachi HD44780 driver.    
    
  Ref:
    
  LICENSE: GNU General Public License, version 3 (GPL-3.0)
*****************************************************************/  
#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup()
{
  // initialize serial and wait for port to open:
  Serial.begin(9600);
}//setup

void loop()
{
  // read a byte from the current address of the EEPROM
  value = EEPROM.read(address);
 
  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();
 
  // advance to the next address of the EEPROM
  address = address + 1;
 
  // there are only 512 bytes of EEPROM, from 0 to 511, so if we're
  // on address 512, wrap around to address 0
  if (address == 512)
    address = 0;
   
  delay(500);
}//loop
