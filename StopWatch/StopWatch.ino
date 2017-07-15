// Creating a Stopwatch
unsigned long start, finished, elapsed;
void setup()
{
// 스케치의 메뉴에서 “도구 – 시리얼 모니터”를 선택해서 
// USB포트를 통해 입출력되는 시리얼 데이터 정보를 확인하기 위한 통신속도 설정
 Serial.begin(9600);
  // 아두이노 디지털 입출력 핀의 동작방식 설정: 2번 및 3번 핀을 입력모드로
  pinMode(2, INPUT); // the start button 
  pinMode(3, INPUT); // the stop button
// 회로도의 D2포트 스위치 S2가 1번 버튼, D3포트 스위치 S1이 2번 버튼  
// USB포트를 통해 출력되는 (시리얼 데이터) 정보
Serial.println("Press 1 for Start/reset, 2 for elapsed time");
}
void displayResult()
{
  float h, m, s, ms;
  unsigned long over;
  elapsed = finished - start;
  h = int(elapsed / 3600000);
  over = elapsed % 3600000;
  m = int(over / 60000);
  over = over % 60000;
  s = int(over / 1000);
  ms = over % 1000;
  Serial.print("Raw elapsed time: ");
  Serial.println(elapsed);
  Serial.print("Elapsed time: ");
  Serial.print(h, 0);
  Serial.print("h ");
  Serial.print(m, 0);
  Serial.print("m ");
  Serial.print(s, 0);
  Serial.print("s ");
  Serial.print(ms, 0);
  Serial.println("ms");
  Serial.println();
}
void loop()
{
  if (digitalRead(2) == HIGH)
  {
    start = millis();
    delay(200); // for debounce
    Serial.println("Started...");
  }

  if (digitalRead(3) == HIGH)
  {
    finished = millis();
    delay(200); // for debounce
    displayResult();
  }
}
