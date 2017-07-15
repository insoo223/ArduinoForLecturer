#define BlinkInterval  300


int LED_Start = 2;
int LED_End = 7;
int BoardLED = 13;
int i;

void setup() {                
  for (i=LED_Start; i<=LED_End; i++)
    pinMode(i, OUTPUT);    
  pinMode(BoardLED, OUTPUT);      
  digitalWrite(BoardLED, LOW);
}

void loop() {
  for (i=LED_Start; i<=LED_End; i++)
  {
    digitalWrite(i, HIGH);
    delay(BlinkInterval); 
    digitalWrite(i, LOW); 
    delay(BlinkInterval); 
  }
} 
