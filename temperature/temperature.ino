int POT_PIN = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(0);
  int dat = (125*val)>>8;
  Serial.print("Temp:");
  Serial.print(dat);
  Serial.println("C°");
  delay(500);
}
