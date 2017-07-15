/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : CharLCDCursor.ino
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
    lcd.noCursor(); lcd.cursor();
    
    3) 1st line: "hello, world!" and at theright side of exclamation mark, cursor on & off
       2nd line: nothing

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
    
  Ref:
    http://www.shieldlist.org/dfrobot/lcd
    https://www.dfrobot.com/wiki/index.php/Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009) 
    http://www.arduino.cc/en/Tutorial/LiquidCrystal
    
  LICENSE: GNU General Public License, version 3 (GPL-3.0)
*****************************************************************/  
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() 
{
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // Turn off the cursor:
  lcd.noCursor();
  delay(500);
   // Turn on the cursor:
  lcd.cursor();
  delay(500);
}
