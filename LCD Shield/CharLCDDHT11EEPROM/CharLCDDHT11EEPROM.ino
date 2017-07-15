/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : CharLCDDHT11EEPROM.ino
  Author  : Insoo Kim (insoo@hotmail.com)
  Date    : Dec 12, 2014
  Update  : Mon Aug 10, 2015
            Sat Jul 15, 2017 - Put more comments to lecture 
  Desc    : 
    1) Use 16 by 2 character LCD shield.
    Pins 4, 5, 6, 7, 8, 9 and 10 are used to interface with the LCD. 
    Just one Analog Pin 0 is used to read the five pushbuttons. 

    2) Use <LiquidCrystal> library. 
    Works with all LCD displays that are compatible with the Hitachi HD44780 driver.    

    Use <EEPROM.h> library. 
    Works with all LCD displays that are compatible with the Hitachi HD44780 driver.    
    
    Use a simple DHT library. 
    Easily works with DHT11, c
    
    3) 1st line: "Humidity: " <measured value> %
       2nd line: "Temp: " <measured value> C & time tick

    4) Write the temp & humidity values to the EEPROM and prints it to the serial monitor.
    
  Ref:
    
  LICENSE: GNU General Public License, version 3 (GPL-3.0)
*****************************************************************/  
//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <dht.h>

#define dht_dpin 2 //no ; here. Set equal to channel sensor is on

dht DHT;

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
int BackLightState;

// the current address in the EEPROM
int addr = 0; 
int valHumidity, valTemp;
long valTimeLapse;

void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 Serial.begin (9600);
}//setup
 
void loop()
{
 DHT.read11(dht_dpin);

 lcd.setCursor(0,0);            // move to the begining of the 1st line
 lcd.print("Humidity: ");
 valHumidity = round(DHT.humidity);
 lcd.print(valHumidity);
 lcd.print("%");

 lcd.setCursor(0,1);            // move to the begining of the second line
 lcd.print("Temp: ");
 valTemp = round(DHT.temperature);
 lcd.print(round(DHT.temperature));
 lcd.print((char)223);
 lcd.print("C");
 valTimeLapse = millis()/1000;
 lcd.print(valTimeLapse);
 
 EEPROM.write(addr, valTimeLapse);
 addr = addr + 1;
 if (addr == 512)
   addr = 0;
 EEPROM.write(addr, valTemp);
 addr = addr + 1;
 if (addr == 512)
   addr = 0;
 EEPROM.write(addr, valHumidity);   
 addr = addr + 1;
 if (addr == 512)
   addr = 0;
 
 // advance to the next address.  there are 512 bytes in
 // the EEPROM, so go back to 0 when we hit 512.

 Serial.print("Humidity: ");
 Serial.println(round(DHT.humidity));
 Serial.print("Temp: ");
 Serial.println(round(DHT.temperature));
 //delay(360000); // 10 min
 delay(60000); // 60 sec
} // loop


