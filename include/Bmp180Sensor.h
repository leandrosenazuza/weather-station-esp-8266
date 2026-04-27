#ifndef BMP180_SENSOR_H
#define BMP180_SENSOR_H

#include <Adafruit_BMP085.h>
#include "WeatherSnapshot.h"

class Bmp180Sensor {
public:
  bool begin();
  void read(WeatherSnapshot& snapshot);
  bool isAvailable() const;

private:
  Adafruit_BMP085 bmpSensor_;
  bool isAvailable_ = false;
};

#endif
