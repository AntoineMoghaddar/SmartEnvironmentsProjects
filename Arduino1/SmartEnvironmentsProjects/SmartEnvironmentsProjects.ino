const int ledRed = 8;
const int ledYellow = 9;
const int ldrPin1 = A0;
const int ldrPin2 = A1;
const int ldrPin3 = A2;
int junction;

void setup() {
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
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

  //determining if there is something over the LDR
  if (ldrStatus1 <= 300) {
    value1 = 1;
  } else {
    value1 = 0;
  }

  if (ldrStatus2 <= 700 ) {
    value2 = 1;
  } else {
    value2 = 0;
  }

  if (ldrStatus3 <= 650) {
    value3 = 1;
  } else {
    value3 = 0;

  }

  //transmitting values
  Serial.print("A");
  Serial.println(value1);
  Serial.print("B");
  Serial.println(value2);
  Serial.print("C");
  Serial.println(value3);

  //receiving values and
  //  if (Serial.available() > 0) {
  //    int incomingByte = Serial.read();
  //    if (incomingByte == 2) {
  //      digitalWrite(ledRed, HIGH);
  //      digitalWrite(ledYellow, HIGH);
  //    } else if (incomingByte == 1) {
  //      digitalWrite(ledRed, HIGH);
  //      digitalWrite(ledYellow, LOW);
  //    } else { //when incomingByte == 0
  //      digitalWrite(ledRed, LOW);
  //      digitalWrite(ledYellow, HIGH);
  //    }
  //  }



  if (Serial.available() > 0) {
    junction = Serial.read();
    if (junction == 'L') {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledYellow, LOW);
    } if (junction == 'R') {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, HIGH);
    }
  }
}
