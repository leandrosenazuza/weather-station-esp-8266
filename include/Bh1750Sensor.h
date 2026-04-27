#ifndef BH1750_SENSOR_H
#define BH1750_SENSOR_H

#include <BH1750.h>
#include "WeatherSnapshot.h"

class Bh1750Sensor {
public:
  bool begin();
  void read(WeatherSnapshot& snapshot);
  bool isAvailable() const;

private:
  BH1750 sensor_;
  bool isAvailable_ = false;
};

#endif
