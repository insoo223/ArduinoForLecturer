/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : CharLCDDHT11.ino
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
    
    3) Use a simple DHT library. 
    Easily works with DHT11, c
    
    4) 1st line: "Humidity: " <measured value> %
       2nd line: "Temp: " <measured value> C & time tick

 The circuit:
     * LCD RS pin to digital pin 8
     * LCD Enable pin to digital pin 9
     * LCD D4 pin to digital pin 4
     * LCD D5 pin to digital pin 5
     * LCD D6 pin to digital pin 6
     * LCD D7 pin to digital pin 7
     * LCD R/W pin to ground
     * LCD VSS pin to ground
     * LCD VCC pin to 5V
     * 10K resistor:
     * ends to +5V and ground
     * wiper to LCD VO pin (pin 3)

     DHT11 signal pin 2    
  Ref:
    http://www.shieldlist.org/dfrobot/lcd
    https://www.dfrobot.com/wiki/index.php/Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009) 
    http://www.arduino.cc/en/Tutorial/LiquidCrystal
    
    https://arduino-info.wikispaces.com/DHT11-Humidity-TempSensor
    Simple DHT library. Easy to use!
    https://arduino-info.wikispaces.com/file/view/DHT-lib.zip/545470280/DHT-lib.zip
    
  LICENSE: GNU General Public License, version 3 (GPL-3.0)
*****************************************************************/  

//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
//#include <DHT_SimpleLib.h>
#include <dht.h>

#define dht_dpin 2 //no ; here. Set equal to channel sensor is on

dht DHT;

/*******************************************************

This program will test the LCD panel and the buttons
Mark Bramwell, July 2010

********************************************************/

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 //lcd.print("Push the buttons"); // print a simple message
 // To check buttons' ADC value
 Serial.begin (9600);
 
}
 
void loop()
{
  //**** Core function to get temperature and humidity 
  DHT.read11(dht_dpin);

 lcd.setCursor(0,0);            // move to the begining of the 1st line
 lcd.print("Humidity: ");
 lcd.print(round(DHT.humidity));
 lcd.print("%");

 lcd.setCursor(0,1);            // move to the begining of the second line
 lcd.print("Temp: ");
 lcd.print(round(DHT.temperature));
 lcd.print((char)223); lcd.print("C");
 
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(12, 1);

  // print the number of seconds since reset:
  lcd.print(millis()/1000);
 
   delay(3000);
} // loop

