byte i,cnt;
byte loLED=2, hiLED=3;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for (i=loLED; i<=hiLED; i++)
    pinMode(i, INPUT);
}

void loop() {
  byte bits[2], aBit, aDecimal;
  long randNumber;

  aBit=0;
  aDecimal=0;
  
  randNumber = random(0,3);
  Serial.print("Guess the binary of ");
  Serial.print(randNumber); Serial.print(", ");
  
  delay(5000);
  
  for (i=loLED; i<=hiLED; i++)
  {
    if (digitalRead(i) == 0)
      bits[i-loLED]=1;
     else
      bits[i-loLED]=0;
    delay(20);
  }
  Serial.println();
  Serial.print(cnt++); Serial.print(": ");
  
  for (i=loLED; i<=hiLED; i++)
  {
    aBit = bits[i-loLED];
    aDecimal = aDecimal + pow(2,(i-loLED)) * aBit;
  }

  Serial.print("Your guess is...");Serial.println(aDecimal);
  if (randNumber == aDecimal)
    Serial.println(" You are a genius!");
  else
    Serial.println(" Try again, please.");

  Serial.println();
  delay(500);
}
