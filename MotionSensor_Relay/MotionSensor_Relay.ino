/*----------------------------------------------------
Target: Arduino Uno R3
Author: Insoo Kim ( insoo@hotmail.com )
Created: Mar 14, 2015
Desc: When ambience darkness is over threshold and someone moves,
  then turn on light using relay for 30 secs. 

 ----------------------------------------------------*/
// I/O pin assignment
#define DEBUG 1
#define PIR    2
#define Relay  3
#define Light  A0
#define Sound  A1


// some criteria
//#define DarknessThreshold  10
#define DarknessThreshold  50
#define SoundThreshold  800
#define DurationOfMotionSwitch 30

boolean detectedSound = false;

// ft. prototypes
void chkLightOnly();
void chkMotionOnly();
void chkBothLightAndMotion();

void setup(){
  if (DEBUG)
    Serial.begin(9600);
 pinMode(PIR,INPUT);
 pinMode(Light,INPUT);
 pinMode(Relay, OUTPUT); 
 pinMode(13, OUTPUT);
 digitalWrite(13, LOW);
 }

void loop(){
  chkBothLightAndMotion();
  
  //chkRelay();
  //chkMotionOnly();
  //chkLightOnly();
  /*
  chkSound();
  if (detectedSound)
    turnOnRelay();
  */  
  delay(100);
} //loop

void chkRelay()
{
  Serial.println("Relay HIGH");
  digitalWrite(Relay,HIGH);
  delay(10000);
  Serial.println("Relay LOW");
  digitalWrite(Relay,LOW);
  delay(10000);
}//chkRelay

void   turnOnRelay()
{
   digitalWrite(Relay,HIGH);
   delay(DurationOfMotionSwitch * 1000);
   digitalWrite(Relay,LOW);
   delay(500);
   detectedSound = false;
}

void chkLightOnly()
{
   // if the ambient is dark enough (that is < DarknessThreshold), then switch on the relay
   int brightness = analogRead(Light);
   if (DEBUG)
   {
     Serial.println(brightness);
     delay(500);
   }
   if (brightness < DarknessThreshold) 
     digitalWrite(Relay,HIGH);
   else
     digitalWrite(Relay,LOW);
}//chkLightOnly

void chkMotionOnly()
{
   //if movement is detected then turn on the relay for DurationOfMotionSwitch seconds
   if ( digitalRead(PIR) == HIGH )
   {
     digitalWrite(Relay,HIGH);
     delay(DurationOfMotionSwitch * 1000);
   }
   else
   {
     digitalWrite(Relay,LOW);
     //delay(DurationOfMotionSwitch * 1000);
   }
}//chkMotionOnly

void chkBothLightAndMotion()
{
   // if the ambient is dark enough (that is < 200),
   // AND there detected some movement
   // then switch on the relay for DurationOfMotionSwitch seconds
   int brightness = analogRead(Light);
   if (DEBUG)
   {
     Serial.println(brightness);
     delay(500);
   }
   if ((brightness < DarknessThreshold) && (digitalRead(PIR) == HIGH))
   {
     digitalWrite(Relay,HIGH);
     delay(DurationOfMotionSwitch * 1000);
   }
   else
     digitalWrite(Relay,LOW);
}//chkBothLightAndMotion

void chkSound()
{
  int sensorValue = analogRead(Sound);
  if (sensorValue < SoundThreshold)
  {
    detectedSound = true;
  }
}
