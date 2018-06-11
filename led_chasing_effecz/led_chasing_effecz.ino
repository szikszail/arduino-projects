int BASE = 2;
int NUM = 6;
int METER = 0;
int DELAY = 500;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < NUM; ++i) {
    pinMode(BASE + i, OUTPUT);
  }
}

void loop() {
  int val = analogRead(METER);
  float ratio = val / 1024.0;
  int d = DELAY * ratio;
  
  for (int i = 0; i < NUM; ++i) {
    digitalWrite(BASE + i, LOW);
    delay(d);
  }
  
  Serial.println(val);
  Serial.println(d);
  
  for (int i = 0; i < NUM; ++i) {
    digitalWrite(BASE + i, HIGH);
    delay(d);
  }
}
  
