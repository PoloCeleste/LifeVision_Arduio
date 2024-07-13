# 근무 전 안전검사를 위한 스마트 키오스크 시스템\_센서부

- 근무자의 신체상태 검사 - 심박수, 체온, 음주여부
- RFID를 사용하여 근무자 정보 확인

<br>

- 사용한 보드/센서
  - Arduino Uno R4 Wifi *3, Arduino Uni Mini *1
  - [음주 여부](alcohol/alcohol.ino) - [MQ-3 알코올 센서](https://www.devicemart.co.kr/goods/view?no=1327429) (Analog Pin 사용)
  - [심박수](Heart/Heart.ino) - [MAX30102 산소포화도, 심박수 측정 센서](https://www.devicemart.co.kr/goods/view?no=13137639) (Arduino IDE에서 라이브러리 추가)
  - [체온](Tem/Tem.ino) - [MLX90614 적외선 비접촉 센서](https://www.devicemart.co.kr/goods/view?no=13067760) (MLX90614 라이브러리는 [GitHub](https://github.com/adafruit/Adafruit-MLX90614-Library)에서 다운받아 추가, [BusIO](https://github.com/adafruit/Adafruit_BusIO)라이브러리도 추가 요)
  - [근무자 정보](RFID/RFID.ino) - [MFRC522](https://www.devicemart.co.kr/goods/view?no=1279308) (태그에 "**이름:태그번호(사번)**"으로 저장된 정보 읽어서 메인 시스템으로 전송)
