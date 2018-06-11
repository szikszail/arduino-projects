int RED_LED = 6;
int YELLOW_LED = 4;
int BLUE_LED = 2;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void blink(int led, int d1, int d2) {
  delay(d1);
  digitalWrite(led, HIGH);
  delay(d2);
  digitalWrite(led, LOW);
}

void loop() {
  blink(BLUE_LED, 0, 2000);
  for (int i = 0; i < 3; i++) {
    blink(YELLOW_LED, 500, 500);
  }
  blink(RED_LED, 500, 2000);
}
    
