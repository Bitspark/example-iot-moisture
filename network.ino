#include "definitions.h"

WiFiClient net;
MQTTClient client;

void mqttSetup() {
  WiFi.begin(wifiSSID, wifiPass);
  client.begin(mqttHost, net);
  
  client.onMessage(messageReceived);

  connect();
  subscribe();
}

void mqttLoop() {
  client.loop();
  if (!client.connected()) {
    connect();
    subscribe();
  }
}

void mqttPublish(char topic[], char data[]) {
  client.publish(topic, data);
}

void connect() {
  ledsOff();
  
  ledBlink(LED_BLUE, 1000, 150);
  ledOn(LED_BLUE);
  while (WiFi.status() != WL_CONNECTED) {
    ledOff(LED_BLUE);
    ledBlink(LED_BLUE, 1000, 150);
    ledOn(LED_BLUE);
    delay(100);
  }
  ledOff(LED_BLUE);
  
  ledBlink(LED_BLUE, 1000, 150);
  ledOn(LED_BLUE);
  while (!client.connect(mqttDeviceName, "", "")) {
    ledOff(LED_BLUE);
    ledBlink(LED_BLUE, 1000, 150);
    ledOn(LED_BLUE);
    delay(100);
  }
  ledOff(LED_BLUE);

  // Connection successful
  ledBlink(LED_BLUE, 3000, 1000);
}
