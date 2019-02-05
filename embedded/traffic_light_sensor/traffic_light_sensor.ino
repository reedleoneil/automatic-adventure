#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

int pinInductiveSensor = A0;
int pinRelay = 13;
byte rfid = mfrc522.uid.uidByte;

void setup() {
  Serial.begin(9600);
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card
  pinMode(pinRelay, INPUT);
}

void loop() {
  bool isTrafficLightRed = digitalRead(pinRelay);
  int sensorReading = analogRead(pinInductiveSensor);
  readRFID();

  if (isTrafficLightRed && sensorReading == 0)
    Serial.print("{\"trafficLight\": " + String(isTrafficLightRed) + ", \"lane\": " + String(isTrafficLightRed)  + ", \"rfid\": \"" + String(rfid) +"\"}");

  delay(1000);
}

void readRFID() {
  //Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card. PICC_HaltA() is automatically called.
  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  rfid = mfrc522.uid.uidByte;
}
