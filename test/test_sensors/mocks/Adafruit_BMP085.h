#ifndef MOCK_ADAFRUIT_BMP085_H
#define MOCK_ADAFRUIT_BMP085_H

#include "Arduino.h"

struct MockBmp180State {
  bool beginResult = true;
  float temperature = 0.0f;
  long pressurePa = 0;
};

inline MockBmp180State& getMockBmp180State() {
  static MockBmp180State state;
  return state;
}

class Adafruit_BMP085 {
public:
  bool begin() { return getMockBmp180State().beginResult; }
  float readTemperature() { return getMockBmp180State().temperature; }
  long readPressure() { return getMockBmp180State().pressurePa; }
};

#endif
