#include "Bh1750Sensor.h"

bool Bh1750Sensor::begin() {
  isAvailable_ = sensor_.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
  return isAvailable_;
}

void Bh1750Sensor::read(WeatherSnapshot& snapshot) {
  snapshot.isBh1750Available = isAvailable_;
  snapshot.bh1750Lux = NAN;

  if (!isAvailable_) {
    return;
  }

  snapshot.bh1750Lux = sensor_.readLightLevel();
}

bool Bh1750Sensor::isAvailable() const {
  return isAvailable_;
}
