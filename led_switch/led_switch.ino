int LED_PIN = 11;
int IN_PIN = 7;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(IN_PIN, INPUT);
}

void loop() {
  digitalWrite(LED_PIN, digitalRead(IN_PIN));
}
