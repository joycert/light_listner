#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "secrets.h"

#define LED_PIN 21

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (unsigned int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  Serial.print("Received message on topic ");
  Serial.print(topic);
  Serial.print(": ");
  Serial.println(msg);

  if (msg == "on") {
    digitalWrite(LED_PIN, LOW);
  } else if (msg == "off") {
    digitalWrite(LED_PIN, HIGH);
  }
}


void reconnect() {
  while (!client.connected()) {
    if (client.connect("esp32Client", MQTT_USER, MQTT_PASS)) {
      client.subscribe(MQTT_TOPIC);
    } else {
      delay(2000);
    }
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
  }

  digitalWrite(LED_PIN, LOW); // solid on when Wi-Fi connected

  client.setServer(MQTT_SERVER, 1883);
  client.setCallback(callback);
  client.setKeepAlive(60);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  delay(10); // keeps CPU from being 100% pegged
}
