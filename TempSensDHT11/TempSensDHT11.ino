#include <DHT_SimpleLib.h>

#define LIGHTON_TEMP 25
#define LIGHTON_HUMI 40
#define LED_TEMP 2
#define LED_HUMI 3

#define dht_dpin 7 //no ; here. Set equal to channel sensor is on

dht DHT;
 
void setup(){
  pinMode(dht_dpin, INPUT);
  Serial.begin(9600);
  delay(300);//Let system settle
  Serial.println("Humidity and temperature\n\n");
  delay(700);//Wait rest of 1000ms recommended delay before
}//setup

void loop(){
  //This is the "heart" of the program.
  DHT.read11(dht_dpin);
  
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("% ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C ");
  
  showLEDtemp();
  showLEDhumi();
  
  delay(3000);//Don't try to access too frequently... in theory
  //should be once per two seconds, fastest,
  //but seems to work after 0.8 second.
}// loop()

void showLEDtemp()
{
 if (DHT.temperature > LIGHTON_TEMP)
  digitalWrite(LED_TEMP, HIGH);
 else
  digitalWrite(LED_TEMP, LOW);
}//showLEDtemp

void showLEDhumi()
{
 if (DHT.humidity > LIGHTON_HUMI)
  digitalWrite(LED_HUMI, HIGH);
 else
  digitalWrite(LED_HUMI, LOW);
}//showLEDhumi
  
