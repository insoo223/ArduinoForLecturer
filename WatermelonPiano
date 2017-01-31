/* WaterMelonPiano.ino
Author: Insoo Kim (insoo@hotmail.com )
Date: 2015.7.5 Sun
Title: 아두이노로 만든 수박 피아노 (미디 키보드) 
  Arduino piano using water melon 
Desc: 물은 전기가 통하고, 수분이 있는 과일은 대부분 적당량의 전류가 
  흐를 수 있으므로 인체 접촉 스위치 기능을 아두이노에 구현해서, 
  간단한 전자 피아노를 만들어 봅니다.
  Water is conductive to electricity, so fruits can behave 
  as good electrical wire. Using shell of water melon, 
  we can play a simple piano or MIDI keyboard.
YouTube: https://www.youtube.com/watch?v=_5zMX5VxZTk
Ref: 
 */

#include "pitches.h"
// notes in the octave:
int gameMelody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
int octave[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int gameMelodyDurations[] = {4, 8, 8, 4,4,4,4,4 };
int noteDurations[] = {4,4,4,4,4 };

// Pin for the LED
int LEDPin = 13;
int speakerPin = 13;

// Pin to connect to your drawing
int DoPin = 3;
int RePin = 4;
int MiPin = 5;
int FaPin = 6;
int SolPin = 7;
int LaPin = 8;
int SiPin = 9;
int DoHiPin = 10;

// This is how high the sensor needs to read in order
//  to trigger a touch.  You'll find this number
//  by trial and error, or you could take readings at 
//  the start of the program to dynamically calculate this.
//int touchedCutoff = 50;
int touchedCutoff = 40;

void setup(){
  Serial.begin(9600);
  // Set up the LED
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
  pinMode(speakerPin, OUTPUT);
  digitalWrite(speakerPin, LOW);
}//setup

//-----------------------------------------------------------
void loop(){
  // If the capacitive sensor reads above a certain threshold,
  //  turn on the LED
  //Serial.println(touchedCutoff);
  chkPin();
  //playGameMelody();
  //playSinglePitch(octave[0],4);
  //delay(500);
}//loop

//********************************************************
void chkPin()
{
  int i;
  int touchVal;

  //for (i=DoPin; i<=FaPin; i++)
  for (i=DoPin; i<=DoHiPin; i++)
  {
    touchVal = readCapacitivePin(i);
    /*
    switch (i)
    {
      case 7:
        touchedCutoff = 60;
        break;
      case 10:
        touchedCutoff = 100;
        break;
    }
    */    
    Serial.print(i);
    Serial.print(": ");
    Serial.println(touchVal);
    if ( touchVal > touchedCutoff) 
    //if ( touchVal < touchedCutoff) 
    {
      //digitalWrite(LEDPin, HIGH);
      //playGameMelody();
      if (i==10)
        //playGameMelody();
        playSinglePitch(octave[i-DoPin],4);
      else
        playSinglePitch(octave[i-DoPin],4);
      //playSinglePitches();
      Serial.print("Pin: ");
      Serial.print(i);
      Serial.print(", ");
      Serial.println(touchVal);
    }//if ( touchVal > touchedCutoff) 
    else
    {
      /*
      Serial.print("Pin: ");
      Serial.print(i);
      Serial.print(", NOT yet over the hump");
      Serial.println(touchVal);
      */
    }
  }//for i
}//chkPin

//-----------------------------------------------------------
// readCapacitivePin
//  Input: Arduino pin number
//  Output: A number, from 0 to 17 expressing
//          how much capacitance is on the pin
//  When you touch the pin, or whatever you have
//  attached to it, the number will get higher
//  In order for this to work now,
// The pin should have a 1+Megaohm resistor pulling
//  it up to +5v.
uint8_t readCapacitivePin(int pinToMeasure)
{
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;

  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  byte bitmask;
  
  //아두이노 디지털 입출력 핀 0 - 7: PORTD (8pins)
  if ((pinToMeasure >= 0) && (pinToMeasure <= 7))
  {
    port = &PORTD;
    ddr = &DDRD;
    bitmask = 1 << pinToMeasure;
    pin = &PIND;
  }
  
  //아두이노 디지털 입출력 핀 8 - 13: PORTB (6pins)
  if ((pinToMeasure > 7) && (pinToMeasure <= 13))
  {
    port = &PORTB;
    ddr = &DDRB;
    bitmask = 1 << (pinToMeasure - 8);
    pin = &PINB;
  }
  
  //아두이노 디지털 입출력 핀 14 - 19: PORTC (6pins)
  if ((pinToMeasure > 13) && (pinToMeasure <= 19)){
    port = &PORTC;
    ddr = &DDRC;
    bitmask = 1 << (pinToMeasure - 14);
    pin = &PINC;
  }
  
  //핀이 담고 있는 전하량을 우선 방전시킴 
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  
  delay(1);
  
  // Make the pin an input WITHOUT the internal pull-up on
  *ddr &= ~(bitmask);
  // Now see how long the pin to get pulled up
  int cycles = 16000;
  for(int i = 0; i < cycles; i++){
    if (*pin & bitmask){
      cycles = i;
      break;
    }
  }
  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  
  return cycles;
}//readCapacitivePin

//********************************************************
void playGameMelody()
{
  // iterate over the notes of the octave:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/gameMelodyDurations[thisNote];
    tone(speakerPin, gameMelody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }
} //playGameMelody

//********************************************************
void playSinglePitch(int pitch, int duration)
{
  // iterate over the notes of the octave:
  //for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/duration;
    tone(speakerPin, pitch,noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  //}
} //playSinglePitch

//********************************************************
void playSinglePitches()
{
  // iterate over the notes of the octave:
  for (int thisNote = 0; thisNote < 5; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(speakerPin, octave[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }
} //playSinglePitches

