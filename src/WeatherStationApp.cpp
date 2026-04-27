#include "WeatherStationApp.h"

#include <Wire.h>

#include "hardware_config.h"

WeatherStationApp::WeatherStationApp()
  : dht11Sensor_(HardwareConfig::kDht11DataGpio, HardwareConfig::kDht11SensorType),
    displayPresenter_(
      HardwareConfig::kDisplayScreenWidth,
      HardwareConfig::kDisplayScreenHeight,
      &Wire,
      HardwareConfig::kDisplayOledResetPin
    ) {}

void WeatherStationApp::begin() {
  serialReporter_.begin(HardwareConfig::kSerialBaudRate);

  dht11Sensor_.begin();
  Wire.begin(HardwareConfig::kOledI2cSdaGpio, HardwareConfig::kOledI2cSclGpio);

  if (!displayPresenter_.begin(HardwareConfig::kOledI2cAddress)) {
    serialReporter_.printOledNotFound();
    while (true) {
      delay(1000);
    }
  }

  displayPresenter_.showStartup();
  delay(HardwareConfig::kStartupSplashDelayMs);

  if (!bmp180Sensor_.begin()) {
    serialReporter_.printBmp180NotFound();
  }

  if (!bh1750Sensor_.begin()) {
    serialReporter_.printBh1750NotFound();
  }
}

void WeatherStationApp::tick() {
  WeatherSnapshot snapshot;

  dht11Sensor_.read(snapshot);
  bmp180Sensor_.read(snapshot);
  bh1750Sensor_.read(snapshot);

  displayPresenter_.render(snapshot);
  serialReporter_.printReport(snapshot);

  delay(HardwareConfig::kMainLoopDelayMs);
}
