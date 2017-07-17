/**************************************************************
  Target MCU: Arduino Uno R3
  Clock type: External
  Clock speed: 16Mhz
  Name    : SwitchInput.ino
  Author  : Insoo Kim (insoo@hotmail.com)
  Date    : Nov 26, 2014
  Update  : Mon Aug 10, 2015
            Sat Jul 15, 2017 - Put more comments to lecture 
  Desc    : 
    0) Reads a digital input pin and prints the result to the serial monitor
    1 or 0 will show up.
    
    1) The push button is "pull-up resistored", so that push the button goes LOW.
    
    2) Test is done using 3cm * 7cm glass fiber custom board 
    with 6 3mm LEDs easily attached to digital IO pin from 2 to 7, 
    and on pin13, 1 button switch working with pull-up resistor.
    This board need to have Vcc supply to the slot beside the button switch. 

 The circuit:
    
  Ref:
    
  LICENSE: GNU General Public License, version 3 (GPL-3.0)
*****************************************************************/  

// digital pin 13 has a pushbutton attached to it. Give it a name:
int pushButton = 13;

// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}//setup

// the loop routine runs over and over again forever:
void loop() 
{
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1000);        // delay in between reads for stability
}//loop
