// TemperatureSensorLM335

#include <math.h>

//this sets the ground pin to LOW and the input voltage pin to high
void setup()
{
  Serial.begin(9600);

  pinMode(13, OUTPUT);  
  digitalWrite(13, LOW);
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
  rawvoltage = analogRead(A0);
  millivolts = (rawvoltage/1023.0) * 5000;
  kelvin = (millivolts/10);
  
  celsius= kelvin - 273.15;
  intCel = (int)round(celsius);
  // Serial port printing for debugging
  Serial.print(cnt++); Serial.print(", ");
  Serial.print(millivolts); Serial.print("[mV] ");
  Serial.print(intCel);
  Serial.print(" round of");
  Serial.print(celsius);
  Serial.println(" degrees Celsius");
  
  delay(5000); // 5 seconds
}
