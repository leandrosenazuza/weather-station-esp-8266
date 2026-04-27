#ifndef DISPLAY_PRESENTER_H
#define DISPLAY_PRESENTER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "WeatherSnapshot.h"

class DisplayPresenter {
public:
  DisplayPresenter(uint8_t width, uint8_t height, TwoWire* wire, int8_t resetPin);

  bool begin(uint8_t i2cAddress);
  void showStartup();
  void render(const WeatherSnapshot& snapshot);

private:
  Adafruit_SSD1306 display_;
};

#endif
