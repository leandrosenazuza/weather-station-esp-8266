#include "Bmp180Sensor.h"

bool Bmp180Sensor::begin() {
  isAvailable_ = bmpSensor_.begin();
  return isAvailable_;
}

void Bmp180Sensor::read(WeatherSnapshot& snapshot) {
  snapshot.isBmp180Available = isAvailable_;
  snapshot.bmpTemperatureCelsius = NAN;
  snapshot.bmpPressureHpa = NAN;

  if (!isAvailable_) {
    return;
  }

  snapshot.bmpTemperatureCelsius = bmpSensor_.readTemperature();
  snapshot.bmpPressureHpa = bmpSensor_.readPressure() / 100.0f;
}

bool Bmp180Sensor::isAvailable() const {
  return isAvailable_;
}
