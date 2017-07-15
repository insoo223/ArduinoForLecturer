/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : CharLCDCustomChar.ino
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
    lcd.createChar
    
    3) 1st line: smiley, frownie, armsdown, armsup, heart
       2nd line: armsdown, armsup animation

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

// make some custom characters:
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};//heart[8]

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};//smiley[8]

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};//frownie[8]

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};//armsDown[8]

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};//armsUp[8]

void setup() {
  // initialize LCD and set up the number of columns and rows: 
  lcd.begin(16, 2);
  
  // create a new character
  //lcd.createChar(0, heart);
  lcd.createChar(5, heart);
  // create a new character
  lcd.createChar(1, smiley);
  // create a new character
  lcd.createChar(2, frownie);
  // create a new character
  lcd.createChar(3, armsDown);  
  // create a new character
  lcd.createChar(4, armsUp);  

  // Print a message to the lcd.
  lcd.print("I "); 
  lcd.write(byte(0)); // when calling lcd.write() '0' must be cast as a byte
  lcd.print(" Arduino! ");
  lcd.write(1);

}//setup

void loop() 
{
  // read the potentiometer on A0:
  int sensorReading = analogRead(A0);
  // map the result to 200 - 1000:
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  
  lcd.setCursor(0, 0);
  // draw smile
  lcd.write(1);
  delay(200); 
  
  lcd.setCursor(2, 0);
  // draw frownie
  lcd.write(2);
  delay(200); 
  
  lcd.setCursor(4, 0);
  // draw heart
  lcd.write(3);
  delay(200); 

  lcd.setCursor(6, 0);
  // draw heart
  lcd.write(4);
  delay(200);
 
  lcd.setCursor(8, 0);
  // draw heart (PROBLEMATIC!)
  lcd.write(5);
  delay(200); 

  // animation 
  lcd.setCursor(4, 1);
  // draw him arms up:
  lcd.write(4);
  delay(delayTime); 
 // set the cursor to the bottom row, 5th position:
  lcd.setCursor(4, 1);
  // draw the little man, arms down:
  lcd.write(3);
  delay(delayTime);
  lcd.setCursor(4, 1);
  // draw him arms up:
  lcd.write(4);
  delay(delayTime); 
}//loop
