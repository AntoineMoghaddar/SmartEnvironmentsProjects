const int ldrPin1 = A0;
const int ldrPin2 = A1;
const int ldrPin3 = A2;


void setup() {
  Serial.begin(9600);
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
  if (ldrStatus1 <= 500) {
    value1 = 1;
  } else {
    value1 = 0;
  }

  if (ldrStatus2 <= 500) {
    value2 = 1;
  } else {
    value2 = 0;
  }

  if (ldrStatus3 <= 400) {
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
  delay(50);
}
