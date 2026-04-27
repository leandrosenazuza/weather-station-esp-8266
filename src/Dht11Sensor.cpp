#include "Dht11Sensor.h"

Dht11Sensor::Dht11Sensor(uint8_t dataGpio, uint8_t sensorType)
  : dhtSensor_(dataGpio, sensorType) {}

bool Dht11Sensor::begin() {
  dhtSensor_.begin();
  return true;
}

void Dht11Sensor::read(WeatherSnapshot& snapshot) {
  snapshot.dhtHumidityPercent = dhtSensor_.readHumidity();
  snapshot.dhtTemperatureCelsius = dhtSensor_.readTemperature();
}
