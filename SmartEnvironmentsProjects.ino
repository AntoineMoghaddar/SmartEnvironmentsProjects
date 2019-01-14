const int ledPin = 13;
const int buzzerPin = 12;
const int ldrPin = A0;
const int ldrPin2 = A1;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
}

void loop() {
  boolean value1;
  boolean value2;
  int ldrStatus = analogRead(ldrPin);
  int ldrStatus2 = analogRead(ldrPin2);
  //Serial.println(ldrStatus2);
  //Serial.println(ldrStatus);
  if (ldrStatus <= 500) {
    value1 = 1;
  } else {
    value1 = 0;
  }

  if (ldrStatus2 <= 500) {
    value2 = 1;
  } else {
    value2 = 0;
  }

  int valueTot = value1 + value2;

  Serial.println('A1 ' + value1);
  Serial.println('A2 ' + value2);
//  if (valueTot == 2) {
//    digitalWrite(ledPin, HIGH);
//  } else {
//    digitalWrite(ledPin, LOW);
//  }
}
