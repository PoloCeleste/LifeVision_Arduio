#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9
#define SS_PIN          10

MFRC522 mfrc522(SS_PIN, RST_PIN);

byte nuidPICC[4];

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void printDec(byte *buffer) {
  long n = 0;
  for (byte i = 0; i < 3; i++) {
    n = n * 256 + buffer[i];
  }
  Serial.print(n);
}

void loop() {
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  byte block;
  byte len;
  MFRC522::StatusCode status;

  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  if (mfrc522.uid.uidByte[0] != nuidPICC[0] || 
    mfrc522.uid.uidByte[1] != nuidPICC[1] || 
    mfrc522.uid.uidByte[2] != nuidPICC[2] || 
    mfrc522.uid.uidByte[3] != nuidPICC[3] ) {

    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = mfrc522.uid.uidByte[i];
    }
    printDec(mfrc522.uid.uidByte);
    Serial.print(':');
  }
  else Serial.println(F("Card read previously."));

  byte buffer[18];
  block = 1;

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  for (uint8_t i = 0; i < 16; i++) {
    Serial.write(buffer[i] );
  }
  Serial.println();
  delay(500);

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}