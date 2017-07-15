
//**************************************************************//
// Target MCU & internal clock speed: Arduino Uno
//  Name    : SensTouchSwitch.ino
//  Author  : Insoo Kim
//  Date    : April 01, 2015    
//  Notes   : Sensing touch switch
//      and show on the LED if there is.
//*****************************************************************/  

#define touchSW 4
#define LED 2

void setup()
{
  pinMode(touchSW, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

byte cnt = 0;
void loop()
{
  if (digitalRead(touchSW) == HIGH)
  {
    cnt++;
    digitalWrite(LED, HIGH);
    Serial.print(cnt);
    Serial.println(": Pressed");
    delay(150);
  }
  else
  {
    digitalWrite(LED, LOW);
    //Serial.println("Released");
  }
  delay(50);
}
