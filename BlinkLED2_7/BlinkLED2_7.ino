/*
  BlinkLED2_7
  Turns on & off LEDs from LED_Start to LED_End, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.

#define BlinkInterval  300

// give it a name:
int LED_Start = 2;
int LED_End = 7;
int BoardLED = 13;
int i;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (i=LED_Start; i<=LED_End; i++)
    pinMode(i, OUTPUT);    
  pinMode(BoardLED, OUTPUT);      
  digitalWrite(BoardLED, LOW);    // turn the LED off by making the voltage LOW
}

// the loop routine runs over and over again forever:
void loop() {
  for (i=LED_Start; i<=LED_End; i++)
  {
    digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(BlinkInterval);               // wait for a second
    digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
    delay(BlinkInterval);               // wait for a second
  }
} 
