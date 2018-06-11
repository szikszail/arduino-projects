int BUZZER = 7;

void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  unsigned char i,j;
  while (1) {
    for (i = 0; i < 80; ++i) {
      digitalWrite(BUZZER, HIGH);
      delay(1);
      digitalWrite(BUZZER, LOW);
      delay(1);
    }
    for (i = 0; i < 100; ++i) {
      digitalWrite(BUZZER, HIGH);
      digitalWrite(BUZZER, LOW);
      delay(2);
    }
  }
}
