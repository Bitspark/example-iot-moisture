#include "definitions.h"

void ledSetup() {
  pinMode(D5, OUTPUT); // RED LED
  pinMode(D6, OUTPUT); // GREEN LED
  pinMode(D7, OUTPUT); // BLUE LED
}

void ledSwitch(int ledID, int val) {
  switch (ledID) {
  case LED_RED:
  digitalWrite(D5, val);
  break;
  case LED_GREEN:
  digitalWrite(D6, val);
  break;
  case LED_BLUE:
  digitalWrite(D7, val);
  break;
  }
}

void ledOff(int ledID) {
  ledSwitch(ledID, LOW);
}

void ledOn(int ledID) {
  ledSwitch(ledID, HIGH);
}

void ledsOff() {
  ledOff(LED_RED);
  ledOff(LED_GREEN);
  ledOff(LED_BLUE);
}

void ledSignal(int ledID, int duration) {
    ledOn(LED_RED);
    delay(500);
    ledOff(LED_RED);
}

void ledBlink(int ledID, int duration, int delayTime) {
  for (int i = 0; i < duration; i += delayTime) {
    ledOn(ledID);
    delay(delayTime / 2);
    ledOff(ledID);
    delay(delayTime / 2);
  }
}
