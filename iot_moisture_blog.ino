#include "definitions.h"

DHT dht(D3, DHT11);

unsigned long lastMeasure = 0;
unsigned long lastLight = 0;

void setup() {
  Serial.begin(9600);
  
  dht.begin();
  
  ledSetup();
  mqttSetup();

  lastMeasure = millis();
}

void loop() {  
  mqttLoop();

  if (lastLight != 0 && millis() - lastLight > 2000) {
    lastLight = millis();
    ledsOff();
  }
  
  if (millis() - lastMeasure > 10000) {
    lastMeasure = millis();
    
    ledOn(LED_BLUE);
    float moisture = analogRead(A0);
    ledOff(LED_BLUE);
    
    if (isnan(moisture)) {
      ledOn(LED_RED);
    } else {
      ledOn(LED_GREEN);
      char str[16];
      sprintf(str, "%.0f", moisture);
      mqttPublish("/bitspark/office/plant/coffee1/moisture", str);
    }

    lastLight = millis();
  }
}

void messageReceived(String &topic, String &payload) {}

void subscribe() {}
