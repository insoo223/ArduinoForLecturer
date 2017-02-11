/* 코드이름: BinaryGame.ino
 *  첫 창작일: 2017.2.11(토)
 *  첫 창작자: 김인수 ( insoo@hotmail.com )
 *  동작 설명: 간단한 이진수 게임
 *    시리얼 모니터에 0-3사이의 임의의 십진수가 나타나면, 
 *    게임자는 이에 해당하는 이진수를 두개의 슬라이드 스위치로 나타냄.
 *    이 때, 슬라이드 스위치의 On/Off상태가 LED에 나타남.
 *    5초안에 스위치의 조합이 정확한 이진수를 나타내면, 천재 아니면 재시도권함 
 *    
 *  회로도: 아래 스키매틱에 따라 아두이노 보드와 실물을 연결
 *    디지털포트 2, 3에 연결된 슬라이드 스위치 연결되어 있음.
 *    
 *  +5V---+
 *        |
 *        (+)
 *        LED
 *        (-)
 *        |
 *        R (1K)
 *        |
 *        +-------> 디지털포트 2 & 3 
 *        |
 *      +-+-+ 슬라이드 스위치(우측으로 스위치레버를 밀면 ON --> GND)
 *      | | |
 *     NC   GND
 *          
 */

// 반복루프 및 실행횟수 표시 변수
byte i,cnt; 

// 게임기에 사용될 맨 하위 및 상위 포트
byte loLED=2, hiLED=3; 

void setup() {
  // 시리얼통신 준비
  Serial.begin(9600);
  
  // 아날로그 포트의 플로팅 값을 랜덤씨앗으로
  randomSeed(analogRead(0)); 
  
  // 슬라이드 스위치가 연결된 각 디지털포트를 입력모드로 설정
  // for 반복루프에 관여하는 문장이 한 문장 밖에 없으므로 { } 생략 가능
  for (i=loLED; i<=hiLED; i++) 
    pinMode(i, INPUT);
}

void loop() {
  byte bits[2]; //슬라이드 스위치 상태 저장 배열
  byte aBit; //슬라이드 스위치 위치에 따른 배열값에 해당하는 비트
  byte aDecimal; //슬라이드 스위치 조합값 전체에 해당하는 십진수
  long randNumber; //게임용 랜덤숫자

  // 슬라이드 스위치 각 비트값 및 전체 조합값 초기화
  aBit=0;
  aDecimal=0;

  // 0~3까지 랜덤 숫자 발생
  randNumber = random(0,3);

  // 시리얼모니터 통해서 문제 출제
  Serial.print("Guess the binary of ");
  Serial.print(randNumber); Serial.print(", ");

  // 5초간 여유를 주어, 슬라이드 스위치로 이진수 조합을 표현하게
  delay(5000);

  // 배열의 0번 부터 슬라이드 스위치의 값을 넣기 위해 i-loLED
  // 본 회로도에서 디지털포트에 연결된 슬라이드 스위치는 On일 때 GND가 되고 
  //  LED가 켜진 상태로 보인다.
  // 따라서, 디지털 입력 함수로 상태값을 읽으면 On이면 논리 0으로 보이므로,
  //  if문을 사용해서 반대로 바꿔주자.
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

  // 배열에 담긴 비트값을 읽어서 십진수로 표시한다.
  for (i=loLED; i<=hiLED; i++)
  {
    aBit = bits[i-loLED];
    aDecimal = aDecimal + pow(2,(i-loLED)) * aBit;
  }

  // 만약에 슬라이스 스위치의 조합값과 문제의 수치가 일치하면
  //  천재, 아니면 다시시도를 시리얼모니터에 표시
  Serial.print("Your guess is...");Serial.println(aDecimal);
  if (randNumber == aDecimal)
    Serial.println(" You are a genius!");
  else
    Serial.println(" Try again, please.");

  Serial.println();
  delay(500);
}
