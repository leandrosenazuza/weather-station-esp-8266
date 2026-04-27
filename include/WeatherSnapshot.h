#ifndef WEATHER_SNAPSHOT_H
#define WEATHER_SNAPSHOT_H

#include <Arduino.h>

struct WeatherSnapshot {
  float dhtHumidityPercent = NAN;
  float dhtTemperatureCelsius = NAN;

  float bmpTemperatureCelsius = NAN;
  float bmpPressureHpa = NAN;
  bool isBmp180Available = false;

  float bh1750Lux = NAN;
  bool isBh1750Available = false;

  bool hasDhtReadingError() const {
    return isnan(dhtHumidityPercent) || isnan(dhtTemperatureCelsius);
  }

  bool allRequiredSensorsReady() const {
    return !hasDhtReadingError() && isBmp180Available && isBh1750Available;
  }
};

#endif
