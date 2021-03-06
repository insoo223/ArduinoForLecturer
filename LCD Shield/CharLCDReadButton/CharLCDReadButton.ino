/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : CharLCDReadButton.ino
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

    3) 1st line: "Push the buttons "
       2nd line: initially "NONE: " & time tick, when press buttons show corresponding mesages
    
  Ref:
    
  LICENSE: GNU General Public License, version 3 (GPL-3.0)
*****************************************************************/  
//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
int BackLightState;

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
#define BackLightPin   10

void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("Push the buttons"); // print a simple message
 // To check buttons' ADC value
 Serial.begin (9600);
 
}
 
void loop()
{
 lcd.setCursor(9,1);            // move cursor to second line "1" and 9 spaces over
 lcd.print(millis()/1000);      // display seconds elapsed since power-up

 lcd.setCursor(0,1);            // move to the begining of the second line
 lcd_key = read_LCD_buttons();  // read the buttons

 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     lcd.print("RIGHT ");
     break;
     }
   case btnLEFT:
     {
     lcd.print("LEFT   ");
     break;
     }
   case btnUP:
     {
     lcd.print("UP    ");
     break;
     }
   case btnDOWN:
     {
     lcd.print("DOWN  ");
     break;
     }
   case btnSELECT:
     {
     lcd.print("SELECT");
     break;
     }
     case btnNONE:
     {
     lcd.print("NONE  ");
     break;
     }
 } // switch
 delay(500);

}

// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // To check buttons' ADC value
 Serial.print("Button ADC: ");
 Serial.println(adc_key_in);

 BackLightState = digitalRead(BackLightPin);
 Serial.print("BackLight Status: ");
 Serial.println(BackLightState);
 // my buttons when read are centered at these values: 0, 144, 329, 504, 741
 // Insoo's buttons are: 0, 100, 258, 412, 640
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.1 us this threshold
 if (adc_key_in < 50)   return btnRIGHT;  
 /*-- original threshold values
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 450)  return btnDOWN; 
 if (adc_key_in < 650)  return btnLEFT; 
 if (adc_key_in < 850)  return btnSELECT;  
 */
 if (adc_key_in < 200)  return btnUP; 
 if (adc_key_in < 300)  return btnDOWN; 
 if (adc_key_in < 500)  return btnLEFT; 
 if (adc_key_in < 700)  return btnSELECT;  

 // For V1.0 comment the other threshold and use the one below:
/*
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   
*/

 return btnNONE;  // when all others fail, return this...
 
} // read_LCD_buttons
