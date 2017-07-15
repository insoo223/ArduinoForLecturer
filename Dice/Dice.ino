
#define SWpin 13
#define startLEDpin 2
#define endLEDpin 7
byte i;
byte sel;

void setup()
{
  for (i=startLEDpin; i<=endLEDpin; i++)
    pinMode(i, OUTPUT);
  pinMode(SWpin, INPUT);
}//setup

void loop ()
{
  
  if (digitalRead(SWpin) == HIGH)
    for (i=startLEDpin; i<=endLEDpin; i++)
    {
      digitalWrite(i, HIGH);
      delay(10);
      digitalWrite(i, LOW);
      delay(10);
    }
  else
  {
    PORTD = analogRead(A0) % 127 << 2;
    delay(3000);
  }
    
  delay(10);
  
}
