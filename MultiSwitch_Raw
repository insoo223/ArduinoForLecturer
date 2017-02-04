int toggleSwitch1= 2;
int toggleSwitch2= 3;

void setup() {
  Serial.begin(9600);
  pinMode(toggleSwitch1,INPUT);
  pinMode(toggleSwitch2,INPUT);
}

void loop() {
  int toggleState1, toggleState2;

  toggleState1 = digitalRead(toggleSwitch1);
  toggleState2 = digitalRead(toggleSwitch2);

  if (toggleState1 == 1)
    Serial.println ("스위치 1을 눌렀습니다.");
  if (toggleState2 == 1)
    Serial.println ("스위치 2를 눌렀습니다.");
    
  delay(100);
}
