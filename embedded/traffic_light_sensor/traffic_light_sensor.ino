#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 49
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

int pinInductiveSensor = A0;
int pinRelay = 2;
String rfid;

void setup() {
  Serial.begin(9600);
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card
  pinMode(pinRelay, INPUT_PULLUP);
}

void loop() {
  bool isTrafficLightRed = digitalRead(pinRelay);
  int sensorReading = analogRead(pinInductiveSensor);
  readRFID();
  
  if (!isTrafficLightRed && sensorReading == 0)
    Serial.println("{\"trafficLight\": " + String(isTrafficLightRed) + ", \"lane\": " + String(isTrafficLightRed)  + ", \"rfid\": \"" + String(rfid) +"\"}");
  delay(1000);
}

void readRFID() {
  if (mfrc522.PICC_IsNewCardPresent())
  {
        if (mfrc522.PICC_ReadCardSerial())
        {
           rfid = "";
           for (byte i = 0; i < mfrc522.uid.size; i++) {
                  if (String(mfrc522.uid.uidByte[i] < 0x10))
                    rfid += " ";
                    rfid += String(mfrc522.uid.uidByte[i], HEX);
            }
            mfrc522.PICC_HaltA();
        }
  }
}
