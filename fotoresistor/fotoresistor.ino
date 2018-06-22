int POT_PIN = 0;
int LED_PIN = 11;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(LED_PIN, analogRead(POT_PIN));
  delay(10);
}
