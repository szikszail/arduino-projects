int DATA_PIN = 2;
int CLOCK_PIN = 5;
int LATCH_PIN = 4;
int ledState = 0;

const int ON = LOW;
const int OFF = HIGH;

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
};

void updateLEDs(int value) {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, value);
  digitalWrite(LATCH_PIN, HIGH);
}

void loop() {
  for (int i = 0; i < 256; ++i) {
    updateLEDs(i);
    delay(500);
  }
}

