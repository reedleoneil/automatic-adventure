int greenRedInterval = 2000;
int yellowInterval = 500;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(50, OUTPUT);
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

void green(int trafficLight) {
  if (trafficLight == 1) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (trafficLight == 2) {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  } else if (trafficLight ==3) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
}

void yellow(int trafficLight) {
  if (trafficLight == 1) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (trafficLight == 2) {
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  } else if (trafficLight ==3) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
}

void red(int trafficLight) {
  if (trafficLight == 1) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(46, HIGH); // relay
    digitalWrite(48, LOW); // relay
    digitalWrite(50, LOW); // relay
  } else if (trafficLight == 2) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(46, LOW); // relay
    digitalWrite(48, HIGH); // relay
    digitalWrite(50, LOW); // relay
  } else if (trafficLight ==3) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(46, LOW); // relay
    digitalWrite(48, LOW); // relay
    digitalWrite(50, HIGH); // relay
  }
}
