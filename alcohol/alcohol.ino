const int MQ3 = A0; //MQ-3 아날로그 핀 A0에 연결
int value; //알코올 센서 값을 전달할 값을 선언하기

void setup() {
  Serial.begin(9600); //시리얼프린트 시작
}

void loop() {
  value= analogRead(MQ3); //mq3센서의 값을 읽기   
  Serial.println(value); //값 프린트 하기
  delay(1000); //1초마다 한번씩

}