/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : PORTDbuttonCnt.ino
  Author  : Insoo Kim (insoo@hotmail.com)
  Date    : Dec 26, 2014
  Update  : Mon Aug 10, 2015
            Sat Jul 15, 2017 - Put more comments to lecture 
  Desc    : 
    1) Use PORTD of group name of IO pins
    Digital IO pin of Arduino from 1 to, 7 is member of PORTD of ATmega328P MCU.

    2) Count the push button and using PORTD display multiple LEDs with ease.
    
    3) The push button is "pull-up resistored", so that push the button goes LOW.
    
    4) Test is done using 3cm * 7cm glass fiber custom board 
    with 6 3mm LEDs easily attached to digital IO pin from 2 to 7, 
    and on pin13, 1 button switch working with pull-up resistor.
    This board need to have Vcc supply to the slot beside the button switch. 

 The circuit:
    
  Ref:
    
  LICENSE: GNU General Public License, version 3 (GPL-3.0)
*****************************************************************/  

#define BUTTONpin 13
#define DISP_LED_STARTpin 2
#define DISP_LED_Endpin 7

int cnt;

void setup()
{
  int i;
  for (i=DISP_LED_STARTpin; i<=DISP_LED_Endpin; i++)
    pinMode(i, OUTPUT);

  pinMode(BUTTONpin, INPUT); // the start button
}//setup

void loop()
{
  if (digitalRead(BUTTONpin) == LOW)
  {
    delay(200); // for debounce
    cnt++;
    //Show button count from the LED of Pin3
    //Digital pin0 to 7 is grouped as PORTD
    //PORTD = cnt <<3;
    PORTD = cnt << DISP_LED_STARTpin;
    
    //Digital pin8 to 13 is grouped as PORTB
    //Show button count at PORTB LEDs, if the count is over 2^5
    //PORTB = cnt >>5;
  }//if
}//loop
