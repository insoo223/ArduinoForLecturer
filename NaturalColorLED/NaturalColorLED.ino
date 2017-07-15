
#define R 9
#define G 10
#define B 11

byte i;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for (i=R; i<=B; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  randomRobinColor();
}

void randomRobinColor()
{
  byte Rval, Gval, Bval;
  Rval=random(0,255);
  Gval=random(0,255);
  Bval=random(0,255);
  Serial.print(Rval); Serial.print(", ");
  Serial.print(Gval); Serial.print(", ");
  Serial.print(Bval); Serial.println();
  threeColorLED(Rval, Gval, Bval);
  delay(2000);
}

void roundRobinColor()
{
  threeColorLED(255,0,0);
  delay(500);
  threeColorLED(0,255,0);
  delay(500);
  threeColorLED(0,0,255);
  delay(500);
}

void threeColorLED(byte Rval, byte Gval, byte Bval)
{
  analogWrite(R, Rval);
  analogWrite(G, Gval);
  analogWrite(B, Bval);
}
