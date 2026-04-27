#ifndef WEATHER_STATION_APP_H
#define WEATHER_STATION_APP_H

#include "Bh1750Sensor.h"
#include "Bmp180Sensor.h"
#include "Dht11Sensor.h"
#include "DisplayPresenter.h"
#include "SerialReporter.h"
#include "WeatherSnapshot.h"

class WeatherStationApp {
public:
  WeatherStationApp();

  void begin();
  void tick();

private:
  Dht11Sensor dht11Sensor_;
  Bmp180Sensor bmp180Sensor_;
  Bh1750Sensor bh1750Sensor_;
  DisplayPresenter displayPresenter_;
  SerialReporter serialReporter_;
};

#endif
