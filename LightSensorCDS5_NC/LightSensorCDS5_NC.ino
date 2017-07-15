int lightPin = 0; 
int ledPin=11;     

void setup()
{
    Serial.begin(9600); 
}

void loop()
{
    Serial.println(analogRead(lightPin)); 
   delay(3000); 
}
