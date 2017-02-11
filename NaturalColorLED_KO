/* 코드이름: LED_Natural_Colors.ino
 *  첫 창작일: 2017.2.11(토)
 *  첫 창작자: 김인수 ( insoo@hotmail.com )
 *  동작 설명: 3원색 LED 모듈을 analogWrite를 통해 색상 제어
 *    R,G,B 색상을 0-255사이의 값으로 조정하면서 혼합색상 LED 제어
 *    
 *  회로도: 아래 스키매틱에 따라 아두이노 보드와 실물을 연결
 *    PWM가능한 디지털포트 9~11에 각각 R,G,B핀을 연결
 *    
 *    3원색LED 모듈
 *  --+--+--+--+
 *    |  ***   |
 *    |        |
 *  --+--+--+--+
 *    R  G  B  GND (3원색LED 모듈핀)
 *    |  |  |  +-저항(1k)-> 아두이노 GND
 *    |  |  +-------> 아두이노 PWM 가능 디지털 포트 11
 *    |  +-------> 아두이노 PWM 가능 디지털 포트 10
 *    +-------> 아두이노 PWM 가능 디지털 포트 9
 *          
 */

// 3원색 LED모듈의 R, G, B 핀에 아두이노 디지털 PWM 핀 번호 부여
// #define에 의해 정의된 R, G, B의 값은 코드 내에서 변경될 수 없다. 
// 즉, #define에 의해 정의된 것은 변수가 아니라 "상수(constant)"
#define R 9
#define G 10
#define B 11

// 반복루프를 위한 더미 변수(dummy variable)
byte i;

void setup() {
  // R,G,B 랜덤 값이 잘 배정되는지 시리얼모니터에 출력해 보자.
  Serial.begin(9600);
  randomSeed(analogRead(0));

  // 아두이노의 PWM핀에 배정된 순서가 
  // R부터 시작해서 G, B핀 순으로 증가한다고 정의했으므로, for루프에 R,B상수 사용
  for (i=R; i<=B; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  // R, G, B를 순차적으로 한 색깔씩 나타내 보자
  roundRobinColor();
  // 무작위로 색깔을 나타내 보자
  randomRobinColor();
}

// 입출력 변수가 필요없는 사용자 정의 함수
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
  delay(5000);
}//randomRobinColor

// 입출력 변수가 필요없는 사용자 정의 함수
void roundRobinColor()
{
  threeColorLED(255,0,0);
  delay(500);
  threeColorLED(0,255,0);
  delay(500);
  threeColorLED(0,0,255);
  delay(500);
}//roundRobinColor

// 입력 변수가 필요한 사용자 정의 함수
void threeColorLED(byte Rval, byte Gval, byte Bval)
{
  analogWrite(R, Rval);
  analogWrite(G, Gval);
  analogWrite(B, Bval);
}//threeColorLED
