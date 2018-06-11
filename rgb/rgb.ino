int RED = 7;
int GREEN = 6;
int BLUE = 5;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val;
  for (val = 255; val > 0; val--) {
    analogWrite(RED, val);
    analogWrite(GREEN, 255 - val);
    analogWrite(BLUE, 128 - val);
    delay(1);
  }
  for (val = 0; val < 255; val++) {
    analogWrite(RED, val);
    analogWrite(GREEN, 255 - val);
    analogWrite(BLUE, 128 - val);
    delay(1);
  }
  Serial.println(val, DEC);
}
    
