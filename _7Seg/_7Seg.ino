
//Arduino pin 8,7,6,5,4,3,2
int SevenSeg[10] = {
		0b01110111, //0
		0b0fa1000001, //1
		0b00111011, //2
		0b01101011, //3
		0b01001101, //4
		0b01101110, //5
		0b01111100, //6
		0b01000011, //7
		0b01111111, //8
		0b01001111 //9                
	};//SevenSeg[10]

void disp7seg(int);

void setup()
{
  for (byte i=0; i<=8; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  for (byte i=0; i<=9; i++)
  {
    disp7seg(i);
    delay(1000);
  }
}
  
//********************************************************
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

