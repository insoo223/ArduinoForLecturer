/*
이름: MultiSwitch.ino 
설명: 디지털 핀2, 3에 연결된 토글 스위치의 상태를 입력받아서 시리얼 모니터에 표시한다.
작성자: 김인수 ( insoo@hotmail.com )
최초작성일: 2017.1.29
라이센스: This example code is in the public domain.
*/

// 디지털 핀 2,3에 토글 스위치 연결
int toggleSwitch1= 2;
int toggleSwitch2= 3;

// 아두이노는 전원이 들어오면 setup함수를 맨 먼저 딱 한번 실행한다.
void setup() {
  // 시리얼 통신 속도를 9600 BPS(Bits Per Second)로 설정
  Serial.begin(9600);
  // 푸쉬버튼애 연결된 디지털 핀을 모두 입력으로 설정
  pinMode(toggleSwitch1,INPUT);
  pinMode(toggleSwitch2,INPUT);
}

// setup함수를 먼저 실행 후, loop함수를 계속 실행한다. 전원이 꺼질 때 까지.
void loop() {
  // 토글스위치 상태값을 저장하는 변수:
  int toggleState1, toggleState2;

  // 각 토글스위치의 상태를 디지털 입력 받음
  toggleState1 = digitalRead(toggleSwitch1);
  toggleState2 = digitalRead(toggleSwitch2);

  // 어떤 스위치가 눌러졌는지 확인 후, 메시지 출력
  if (toggleState1 == 1)
    Serial.println ("스위치 1을 눌렀습니다.");
  if (toggleState2 == 1)
    Serial.println ("스위치 2를 눌렀습니다.");
    
  // 지연시간이 이 코드에 어떤 영향을 줄까?  
  delay(100);
}
