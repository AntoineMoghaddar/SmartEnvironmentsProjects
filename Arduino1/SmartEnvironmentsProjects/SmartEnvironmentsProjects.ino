const int ledStraight = 8;
const int ledRight = 7;
const int ldrPin1 = A0;
const int ldrPin2 = A1;
const int ldrPin3 = A2;

void setup() {
  Serial.begin(9600);
  pinMode(ledStraight, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(ldrPin1, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(ldrPin3, INPUT);
}

void loop() {
  boolean value1;
  boolean value2;
  boolean value3;
  int ldrStatus1 = analogRead(ldrPin1);
  int ldrStatus2 = analogRead(ldrPin2);
  int ldrStatus3 = analogRead(ldrPin3);
  int directionValue = 0;

  //determining if there is something over the LDR
  if (ldrStatus1 <= 350) {
    value1 = 0;
  } else {
    value1 = 1;
  }

  if (ldrStatus2 <= 350) {
    value2 = 0;
  } else {
    value2 = 1;
  }

  if (ldrStatus3 <= 350) {
    value3 = 0;
  } else {
    value3 = 1;

  }

  if (value1 == 1) {
    directionValue++;
  }
  if (value3 == 1) {
    directionValue++;
  }

  //    //setting up treshholds
  //    Serial.print("A");
  //    Serial.println(ldrStatus1);
  //    Serial.print("B");
  //    Serial.println(ldrStatus2);
  //    Serial.print("C");
  //    Serial.println(ldrStatus3);

  //transmitting values
  Serial.print("A");
  Serial.println(value1);
  Serial.print("B");
  Serial.println(value2);
  Serial.print("C");
  Serial.println(value3);
  Serial.print("D");
  Serial.println(directionValue);

  int junction;
  if (Serial.available() > 0) {
    junction = Serial.read();

    if (junction == 'R') {
      digitalWrite(ledStraight, LOW);
      digitalWrite(ledRight, HIGH);
    }
    if (junction == 'L') {
      digitalWrite(ledStraight, HIGH);
      digitalWrite(ledRight, LOW);
    }
  }
}
