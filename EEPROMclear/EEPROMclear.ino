/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : EEPROMclear.ino
  Author  : Insoo Kim (insoo@hotmail.com)
  Date    : Sat Jul 15, 2017
  Update  : 
  Desc    : 
    1) Clear EEPROM with 10101010, 0xAA

 The circuit:
    
  Ref:
    
  LICENSE: GNU General Public License, version 3 (GPL-3.0)
*****************************************************************/  

#include <EEPROM.h>

// the current address in the EEPROM
int addr = 0; 

void setup()
{
  Serial.begin (9600);
}//setup
 
void loop()
{
 EEPROM.write(addr, 0xAA);
 addr = addr + 1;
 if (addr == 512)
   addr = 0;
 // advance to the next address.  there are 512 bytes in
 // the EEPROM, so go back to 0 when we hit 512.

 Serial.print("EEPROM addr: ");
 Serial.println(addr);
 Serial.print("EEPROM value: ");
 Serial.println(0xAA, HEX);
 //delay(360000); // 10 min
 delay(200); // 0.2 sec

} // loop

