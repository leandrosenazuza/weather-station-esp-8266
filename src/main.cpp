#include "WeatherStationApp.h"

WeatherStationApp app;

void setup() {
  app.begin();
}

void loop() {
  app.tick();
}
