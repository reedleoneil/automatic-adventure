#include <Sim800L.h>
#include <SoftwareSerial.h>

Sim800L gsm(7, 8); // RX, TX

int greenRedInterval = 5000;
int yellowInterval = 1000;

int r1 = 13;
int y1 = 12;
int g1 = 11;

int r2 = 52;
int y2 = 50;
int g2 = 48;

int r3 = 53;
int y3 = 51;
int g3 = 49;

int t1 = 34;
int t2 = 36;
int t3 = 38;

void setup() {
  Serial.begin(9600);
  gsm.begin(4800);   
  gsm.setSleepMode(false);
  
  pinMode(r1, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(y3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(t3, OUTPUT);
}

void loop() {
    green(1);
    red(2);
    red(3);
    delay(greenRedInterval);
    yellow(1);
    red(2);
    red(3);
    delay(yellowInterval);
    red(1);
    green(2);
    red(3);
    delay(greenRedInterval);
    red(1);
    yellow(2);
    red(3);
    delay(yellowInterval);
    red(1);
    red(2);
    green(3);
    delay(greenRedInterval);
    red(1);
    red(2);
    yellow(3);
    delay(yellowInterval);
}

void red(int trafficLight) {
  if (trafficLight == 1) {
    digitalWrite(r1, HIGH);
    digitalWrite(y1, LOW);
    digitalWrite(g1, LOW);
  } else if (trafficLight == 2) {
    digitalWrite(r2, HIGH);
    digitalWrite(y2, LOW);
    digitalWrite(g2, LOW);
  } else if (trafficLight ==3) {
    digitalWrite(r3, HIGH);
    digitalWrite(y3, LOW);
    digitalWrite(g3, LOW);
  }
}

void yellow(int trafficLight) {
  if (trafficLight == 1) {
    digitalWrite(r1, LOW);
    digitalWrite(y1, HIGH);
    digitalWrite(g1, LOW);
  } else if (trafficLight == 2) {
    digitalWrite(r2, LOW);
    digitalWrite(y2, HIGH);
    digitalWrite(g2, LOW);
  } else if (trafficLight ==3) {
    digitalWrite(r3, LOW);
    digitalWrite(y3, HIGH);
    digitalWrite(g3, LOW);
  }
}

void green(int trafficLight) {
  if (trafficLight == 1) {
    digitalWrite(r1, LOW);
    digitalWrite(y1, LOW);
    digitalWrite(g1, HIGH);
    digitalWrite(t1, LOW); // relay
    digitalWrite(t2, HIGH); // relay
    digitalWrite(t3, HIGH); // relay
  } else if (trafficLight == 2) {
    digitalWrite(r2, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(g2, HIGH);
    digitalWrite(t1, HIGH); // relay
    digitalWrite(t2, LOW); // relay
    digitalWrite(t3, HIGH); // relay
  } else if (trafficLight ==3) {
    digitalWrite(r3, LOW);
    digitalWrite(y3, LOW);
    digitalWrite(g3, HIGH);
    digitalWrite(t1, HIGH); // relay
    digitalWrite(t2, HIGH); // relay
    digitalWrite(t3, LOW); // relay
  }
}

void sendMessage(String number, String message)
{
  gsm.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  gsm.println("AT+CMGS=\"" + number + "\"\r"); //Mobile phone number to send message
  delay(1000);
  String SMS = message;
  gsm.println(SMS);
  delay(100);
  gsm.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
