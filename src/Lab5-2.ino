SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

void setup() {
  pinMode(D7, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void loop() {
  uint16_t sMi = 1023;  // Initialize with maximum possible value
  uint16_t sMa = 0;     // Initialize with minimum possible value
  uint16_t sVal;

  for (int i = 0; i < 10; i++) {
    sVal = analogRead(A5);
    sMa = max(sMa, sVal);
    sMi = min(sMi, sVal);
    delay(100);
  }

  sVal = analogRead(A5);
  uint8_t mappedValue = map(sVal, sMi, sMa, 0, 255);
  analogWrite(D7, mappedValue);

  Serial.print("Sensor Value: ");
  Serial.println(sVal);
  Serial.print("Mapped Value: ");
  Serial.println(mappedValue);

}
