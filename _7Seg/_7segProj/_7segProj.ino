
#define SEGPIN_NUM 8
byte segPin[8] = {6,7,8,9,10,11,12,13};
byte buttonPin = 5;

//Arduino pin 6,7,8,9,10,11,12,13
//            A B C D  E  F  G DP
byte segNum[10][8] = {
		{1,1,1,1,1,1,0,0}, //0
		{0,1,1,0,0,0,0,0}, //1
		{1,1,0,1,1,0,1,0}, //2
		{1,1,1,1,0,0,1,0}, //3
		{0,1,1,0,0,1,1,0}, //4
		{1,0,1,1,0,1,1,0}, //5
		{0,0,1,1,1,1,1,0}, //6
		{1,1,1,0,0,0,0,0}, //7
		{1,1,1,1,1,1,1,0}, //8
		{1,1,1,0,0,1,1,0} //9                
	};//SevenSeg[10]

/*
byte segNum[10][8] = {
		0b11111100, //0
		0b01100000, //1
		0b11011010, //2
		0b11110010, //3
		0b01100110, //4
		0b10110110, //5
		0b00111110, //6
		0b11100000, //7
		0b11111110, //8
		0b11100110 //9                
	};//SevenSeg[10]
*/
void setup()
{
  for (byte i=0; i<=SEGPIN_NUM; i++)
    pinMode(segPin[i], OUTPUT);
  pinMode(buttonPin, INPUT);
  chkLED();
  chkNum();
}//setup

void loop()
{
  playDice();
  /*
  for (byte i=0; i<=9; i++)
  {
    disp7seg(i);
    delay(1000);
  }
  */
}
  
//********************************************************
void chkLED()
{
  byte led;
  for (led=0; led<SEGPIN_NUM; led++)
  {
    digitalWrite(segPin[led], HIGH);
    delay(300);
  }//for led
}//chkLED  

//********************************************************
void chkNum()
{
  byte num;
  
  for (num=0; num<10; num++)
  {
    dispNum(num);
    delay(500);
  }//for num
}//chkLED  

//********************************************************
void dispNum(byte num)
{
  byte led;
  
  for (led=0; led<SEGPIN_NUM; led++)
    digitalWrite(segPin[led], segNum[num][led]);
}//dispNum  
//********************************************************
void playDice()
{
  byte buttonStatus = digitalRead(buttonPin);
  static byte finalDiceFace;
  if (buttonStatus == LOW)
    finalDiceFace = randomShow();
  else
    dispResult(finalDiceFace);
}

byte randomShow()
{
  byte num;
  randomSeed(analogRead(A0));
  num = random(1,7);
  dispNum(num);
  delay(10);
  return num;
}

void dispResult(byte finalNum)
{
  dispNum(finalNum);
}
/*
void disp7seg(int num)
{
    //PORTD: 7 6 5 4  3 2 1 0
    //        bit7 6 5 4  3 2 1 0
    //pin       7 6 5 4  3 2 x x
    PORTD = (SevenSeg[num]<<2) & 0xFC;
    
    //PORTB: x x 13 12  11 10 9 8
    //                                      bit0
    //pin   8 
    digitalWrite(8, ((SevenSeg[num]>>6) & 0x01));
}//disp7seg
*/
