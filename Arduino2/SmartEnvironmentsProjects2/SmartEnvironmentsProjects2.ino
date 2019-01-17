const int ldrPin = A0;
const int ldrPin2 = A1;


void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
}

void loop() {
  boolean value1;
  boolean value2;
  int ldrStatus = analogRead(ldrPin);
  int ldrStatus2 = analogRead(ldrPin2);

  //determining if there is something over the LDR
  if (ldrStatus <= 600) {
    value1 = 1;
  } else {
    value1 = 0;
  }

  if (ldrStatus2 <= 650) {
    value2 = 1;
  } else {
    value2 = 0;
  }

  //transmitting values
  Serial.print("A");
  Serial.println(value1);
  Serial.print("B");
  Serial.println(value2);
  delay(50);
}
