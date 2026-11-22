#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22
#define FAN_PIN 2
#define WATER_LED_PIN 4
#define WATER_PIN 34

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
  pinMode(WATER_LED_PIN, OUTPUT);
  Serial.println("Heatwave Controller Ready...");
}

void loop() {
  // 1. Read the sensors
  float temperature = dht.readTemperature();
  int waterRaw = analogRead(WATER_PIN);
  int waterPercent = map(waterRaw, 0, 4095, 0, 100);

  // 2. Decide Cooling Fan (Red LED) Status
  String fanStatus = "OFF";
  if (temperature >= 35.0) {
    digitalWrite(FAN_PIN, HIGH);
    fanStatus = "ON";
  } else {
    digitalWrite(FAN_PIN, LOW);
    fanStatus = "OFF";
  }

  // 3. Decide Water Alert (Blue LED) Status
  String waterAlertStatus = "OFF";
  if (waterPercent <= 40) {
    digitalWrite(WATER_LED_PIN, HIGH);
    waterAlertStatus = "ON";
  } else {
    digitalWrite(WATER_LED_PIN, LOW);
    waterAlertStatus = "OFF";
  }

  // 4. Print the final clean Status Report
  Serial.print("Status Report -> Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Water Tank: ");
  Serial.print(waterPercent);
  Serial.print("% | Cooling Fan (Red LED): ");
  Serial.print(fanStatus);
  Serial.print(" | Water Alert (Blue LED): ");
  Serial.println(waterAlertStatus);

  Serial.println("---");
  delay(2000);
}
