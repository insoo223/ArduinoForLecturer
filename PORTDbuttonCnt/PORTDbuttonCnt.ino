//CountPushButton.ino 
//Count Push Button and display at LEDs

int cnt=0;

void setup()
{
  int i;
  pinMode(2, INPUT); // the start button
  for (i=3; i<=13; i++)
    pinMode(i, OUTPUT);
}//setup

void loop()
{
  if (digitalRead(2) == HIGH)
  {
    delay(200); // for debounce
    cnt++;
    //Show button count from the LED of Pin3
    //Digital pin0 to 7 is grouped as PORTD
    PORTD = cnt <<3;
    
    //Digital pin8 to 13 is grouped as PORTB
    //Show button count at PORTB LEDs, if the count is over 2^5
    PORTB = cnt >>5;
  }//if
}//loop
