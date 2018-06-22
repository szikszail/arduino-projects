int LED_PIN = 4;
int SENSOR_PIN = 5;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int i;
  while (1) {
    i = analogRead(SENSOR_PIN);
    digitalWrite(LED_PIN, i > 512 ? LOW : HIGH);
  }
}
