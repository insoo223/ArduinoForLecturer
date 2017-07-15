// TempSensLM335

#include <math.h>

//this sets the ground pin to LOW and the input voltage pin to high
void setup()
{
  Serial.begin(9600);

  pinMode(13, OUTPUT);  
  digitalWrite(13, LOW);
  
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);  
  pinMode(6, OUTPUT);  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(3000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  
  PORTD = B01101100;  //sets digital pins 6,5,3,2 HIGH
}

int rawvoltage;
int i, cnt; 
float aveRawVtg;
float millivolts;
float kelvin;
float celsius;
int intCel;
 
void loop()
{
  rawvoltage= 0;
  /*
  for (i=0; i<8; i++)
  {
      rawvoltage += analogRead(A0);
    delay(100);
  }
  aveRawVtg = rawvoltage / 8;  
  millivolts = (aveRawVtg/1023.0) * 5000;
  */
  rawvoltage = analogRead(A0);
  millivolts = (rawvoltage/1023.0) * 5000;
  kelvin = (millivolts/10);
  /*
  Serial.print(kelvin);
  Serial.println(" degrees Kelvin");
  */
  
  celsius= kelvin - 273.15;
  intCel = (int)round(celsius);
  // Serial port printing for debugging
  Serial.print(cnt++); Serial.print(", ");
  Serial.print(millivolts); Serial.print("[mV] ");
  Serial.print(intCel);
  Serial.print(" round of");
  Serial.print(celsius);
  Serial.println(" degrees Celsius");

  PORTD = intCel<<2;
  
  /*float fahrenheit= ((celsius * 9)/5 +32);
  Serial.print(fahrenheit);
  Serial.println(" degrees Fahrenheit");
  */
  
  delay(5000); // 5 seconds
}
