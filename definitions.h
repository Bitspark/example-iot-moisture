#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <MQTT.h>
#include <DHT.h>

#define LED_RED 1
#define LED_GREEN 2
#define LED_BLUE 3

const char wifiSSID[] = "YOUR WIFI NAME";
const char wifiPass[] = "YOUR WIFI PASSWORD";
const char mqttHost[] = "YOUR MQTT BROKER IP ADDRESS";
const char mqttDeviceName[] = "DHT11 Sensor";

#endif
