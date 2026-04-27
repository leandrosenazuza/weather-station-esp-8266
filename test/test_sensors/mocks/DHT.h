#ifndef MOCK_DHT_H
#define MOCK_DHT_H

#include "Arduino.h"

#define DHT11 11

struct MockDhtState {
  float humidity = NAN;
  float temperature = NAN;
};

inline MockDhtState& getMockDhtState() {
  static MockDhtState state;
  return state;
}

class DHT {
public:
  DHT(uint8_t pin, uint8_t type)
    : pin_(pin), type_(type) {}

  void begin() {}

  float readHumidity() { return getMockDhtState().humidity; }
  float readTemperature() { return getMockDhtState().temperature; }

private:
  uint8_t pin_;
  uint8_t type_;
};

#endif
