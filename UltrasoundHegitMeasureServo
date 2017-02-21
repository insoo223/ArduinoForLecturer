/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 */
#include <Servo.h> 
#define startDeg 10
#define endDeg 160
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 

//#include "Module_74HC595_7SegTwoDigit.ino"
//Pin connected to ST_CP of 74HC595
byte latchPin = 2;
//Pin connected to SH_CP of 74HC595
byte clockPin = 3;
////Pin connected to DS of 74HC595
byte dataPin = 4;

byte OnesDigit[12] = {
		0b01111110, //0
		0b00000110, //1
		0b10111100, //2
		0b10101110, //3
		0b11000110, //4
		0b11101010, //5
		0b11011010, //6
		0b00100110, //7
		0b11111110, //8
		0b11100110, //9                
		0b00000001, //DP(10)
		0b00000000 //Blank(11)
	};//OnesDigit[12]

byte TensDigit[11] = {
		0b11111010, //0
		0b10010000, //1
		0b01111100, //2
		0b11011100, //3
		0b10010110, //4
		0b11001110, //5
		0b11100110, //6
		0b10011000, //7
		0b11111110, //8
		0b10011110, //9                
		0b00000001 //DP(10)
	};//TensDigit[10]


#define echoPin 10 //7 // Echo Pin
#define trigPin 11 //8 // Trigger Pin
#define LEDPin 9 // out-of-bound LED
#define swPin 12 // measure button
#define servoPin 13 //servo position control

#define DISPTIME 5  //display time [second]

byte maximumRange = 250; // Maximum range needed (default 200)
byte minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

//------------------------------------------------
void setup() {
 //Serial.begin (9600);
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)

 pinMode(swPin, INPUT);
 
 myservo.attach(servoPin);  // attaches the servo on servoPin to the servo object 
}//setup

boolean showTimeOut = false;
byte showCnt=0;
//------------------------------------------------
void loop() 
{
  // continuous measure without interrupt of switch
  //measureUx();

  //switch pressed
  if (digitalRead(swPin) == LOW)
  {
    measureUx();
    showTimeOut = false;
    showCnt=0;
  }//if (digitalRead(swPin) == LOW)
  //switch released
  else
  {
    //if within show time, display the measured distance\
    if (!showTimeOut)
    {
      digitalWrite(latchPin, HIGH);
      showCnt++;
      //delay(500);
    }//if (!showTimeOut)
     
    if (showCnt > DISPTIME*4)
    {
      dispBlank();
      digitalWrite(latchPin, LOW);
      showTimeOut = true;
      //showCnt=0;
    }//if (showCnt > DISPTIME*2)
    delay(100);
  }//else
}//loop

//------------------------------------------------
void measureUx()
{
  int org_dist=80;
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 org_dist = distance;
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 //Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
 }
 else 
 {
   /* Send the distance to the computer using //Serial protocol, and
   turn LED OFF to indicate successful reading. */
   //Serial.println(distance);
   if (distance < 100)
      disp7seg2digits(distance, false, false);
   else if (distance < 200)
   {
     distance = distance - 100;    
     disp7seg2digits(distance, true, false);
   }
   else if (distance < maximumRange)
   {
     distance = distance - 200;
     disp7seg2digits(distance, true, true);
   }
   digitalWrite(LEDPin, LOW); 
   delay(100);
   myservo.write(endDeg);
   delay(300);
   //mininum height: 50cm
   pos = endDeg-(org_dist-50);
   //pos = endDeg-(distance);
   myservo.write(pos);
 }
 
 //Delay 50ms before next reading.
 delay(500);
}//measureUx  

//------------------------------------------------
void dispBlank()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, OnesDigit[11]);
  shiftOut(dataPin, clockPin, MSBFIRST, OnesDigit[11]);
  digitalWrite(latchPin, HIGH);
}

//------------------------------------------------
void disp7seg2digits(int num, boolean DP1, boolean DP10)
{
    digitalWrite(latchPin, LOW);

    if (!DP1)
      shiftOut(dataPin, clockPin, MSBFIRST, OnesDigit[num % 10]);
    else
      shiftOut(dataPin, clockPin, MSBFIRST, OnesDigit[distance % 10] | OnesDigit[10] );

    if (!DP10)
      shiftOut(dataPin, clockPin, MSBFIRST, TensDigit[num / 10]); 
    else
      shiftOut(dataPin, clockPin, MSBFIRST, TensDigit[distance / 10] | OnesDigit[10] ); 
      

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
}
