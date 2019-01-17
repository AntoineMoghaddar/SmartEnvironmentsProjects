const int ledRed = 13;
const int ledYellow = 9;
const int ldrPin = A0;
const int ldrPin2 = A2;
String junction = "";

void setup() {
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
}

void loop() {
  boolean value1;
  boolean value2;
  int ldrStatus = analogRead(ldrPin);
  int ldrStatus2 = analogRead(ldrPin2);

  //determining if there is something over the LDR
  if (ldrStatus <= 650) {
    value1 = 1;
  } else {
    value1 = 0;
  }

  if (ldrStatus2 <= 500 ) {
    value2 = 1;
  } else {
    value2 = 0;
  }

  //transmitting values
  Serial.print("A");
  Serial.println(value1);
  Serial.print("B");
  Serial.println(value2);

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
    if (junction == 1) {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledYellow, LOW);
    } else {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, HIGH);
    }
  }
}
