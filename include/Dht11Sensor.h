#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

#include <DHT.h>
#include "WeatherSnapshot.h"

class Dht11Sensor {
public:
  Dht11Sensor(uint8_t dataGpio, uint8_t sensorType);

  bool begin();
  void read(WeatherSnapshot& snapshot);

private:
  DHT dhtSensor_;
};

#endif
