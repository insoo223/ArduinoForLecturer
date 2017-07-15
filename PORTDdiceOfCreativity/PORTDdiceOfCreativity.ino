/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : PORTDdiceOfCreativity.ino
  Author  : Insoo Kim (insoo@hotmail.com)
  Date    : Dec 26, 2014
  Update  : Mon Aug 10, 2015
            Sat Jul 15, 2017 - Put more comments to lecture 
  Desc    : 
    0) Play dice of creativity!
    
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

#define SWpin 13
#define startLEDpin 2
#define endLEDpin 7

void setup()
{
  byte i;
  for (i=startLEDpin; i<=endLEDpin; i++)
    pinMode(i, OUTPUT);
  pinMode(SWpin, INPUT);
}//setup

void loop ()
{
  byte i;

  if (digitalRead(SWpin) == LOW) // pull-up resistored switch
  {
    PORTD = analogRead(A0) % 127 << 2;
    delay(3000);
  }//if (digitalRead(SWpin) == LOW)
  else
    for (i=startLEDpin; i<=endLEDpin; i++)
    {
      digitalWrite(i, HIGH);
      delay(10);
      digitalWrite(i, LOW);
      delay(10);
    }//for i
    
  delay(10);
}//loop
