#include "DisplayPresenter.h"

#include "string_constants.h"

DisplayPresenter::DisplayPresenter(
  uint8_t width,
  uint8_t height,
  TwoWire* wire,
  int8_t resetPin
)
  : display_(width, height, wire, resetPin) {}

bool DisplayPresenter::begin(uint8_t i2cAddress) {
  if (!display_.begin(SSD1306_SWITCHCAPVCC, i2cAddress)) {
    return false;
  }

  display_.clearDisplay();
  display_.setTextColor(SSD1306_WHITE);
  display_.setTextSize(1);
  return true;
}

void DisplayPresenter::showStartup() {
  display_.clearDisplay();
  display_.setCursor(0, 0);
  display_.println(Strings::kTitleWeatherStation);
  display_.println(Strings::kStatusStarting);
  display_.display();
}

void DisplayPresenter::render(const WeatherSnapshot& snapshot) {
  display_.clearDisplay();
  display_.setTextSize(1);
  display_.setCursor(0, 0);
  display_.println(Strings::kTitleDevice);

  if (snapshot.hasDhtReadingError()) {
    display_.println(Strings::kReadError);
    display_.display();
    return;
  }

  display_.setCursor(0, 10);
  display_.print(Strings::kLabelTempDht);
  display_.print(snapshot.dhtTemperatureCelsius, 1);
  display_.println(Strings::kUnitCelsius);

  display_.setCursor(0, 20);
  display_.print(Strings::kLabelHumidity);
  display_.print(snapshot.dhtHumidityPercent, 0);
  display_.println(Strings::kUnitPercent);

  display_.setCursor(0, 30);
  if (snapshot.isBmp180Available && !isnan(snapshot.bmpTemperatureCelsius)) {
    display_.print(Strings::kLabelTempBmp);
    display_.print(snapshot.bmpTemperatureCelsius, 1);
    display_.println(Strings::kUnitCelsius);
  } else {
    display_.println(Strings::kUnavailableTempBmp);
  }

  display_.setCursor(0, 40);
  if (snapshot.isBmp180Available && !isnan(snapshot.bmpPressureHpa)) {
    display_.print(Strings::kLabelPressure);
    display_.print(snapshot.bmpPressureHpa, 1);
    display_.println(Strings::kUnitHpa);
  } else {
    display_.println(Strings::kUnavailablePressure);
  }

  display_.setCursor(0, 50);
  if (snapshot.isBh1750Available && !isnan(snapshot.bh1750Lux)) {
    display_.print(Strings::kLabelLux);
    display_.print(snapshot.bh1750Lux, 0);
  } else {
    display_.println(Strings::kUnavailableLux);
  }

  display_.display();
}
