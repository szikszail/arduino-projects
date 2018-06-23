#include <IRremote.h>

int RECV_PIN = 2;
int LED_BASE = 4;

long ons[] = { 0x00FFA25D, 0x00FF629D, 0x00FFE21D, 0x00FF22DD, 0x00FF02FD, 0x00FFC23D };
long offs[] = { 0x00FFE01F, 0x00FFA857, 0x00FF906F, 0x00FF6897, 0x00FF9867, 0x00FFB047 };

IRrecv irrecv(RECV_PIN);
decode_results results;

void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.println("Could not decode message");
  } else {
    switch (results->decode_type) {
      case NEC:
        Serial.print("Decoded NEC:");
        break;
      case SONY:
        Serial.print("Decoded SONY:");
        break;
      case RC5:
        Serial.print("Decoded RC5:");
        break;
      case RC6:
        Serial.print("Decoded RC6:");
        break;
    }
    Serial.print(results->value, HEX);
    Serial.print("(");
    Serial.print(results->bits, DEC);
    Serial.println(" bits)");
  }
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");
  for (int i = 0; i < count; i++) {
    if (i % 2) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    } else {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print("");
  }
  Serial.println("");
}

void setup() {
  pinMode(RECV_PIN, INPUT);
  for (int i = 0; i < 6; ++i) {
    pinMode(LED_BASE + i, OUTPUT);
  }
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

int on = 0;
unsigned long last = millis();

void loop() {
  if (irrecv.decode(&results)) {
    if (millis() - last > 250) {
      on = !on;
      digitalWrite(13, on ? HIGH : LOW);
      dump(&results);
    }
    for (int i = 0; i < 6; ++i) {
      if (results.value == ons[i]) {
        digitalWrite(LED_BASE + i, HIGH);
      }
    }
    for (int i = 0; i < 6; ++i) {
      if (results.value == offs[i]) {
        digitalWrite(LED_BASE + i, LOW);
      }
    }
    last = millis();
    irrecv.resume();
  }
}

