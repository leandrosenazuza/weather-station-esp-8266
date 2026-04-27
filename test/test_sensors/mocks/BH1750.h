#ifndef MOCK_BH1750_H
#define MOCK_BH1750_H

#include "Arduino.h"

struct MockBh1750State {
  bool beginResult = true;
  float lux = 0.0f;
};

inline MockBh1750State& getMockBh1750State() {
  static MockBh1750State state;
  return state;
}

class BH1750 {
public:
  enum Mode {
    CONTINUOUS_HIGH_RES_MODE = 0
  };

  bool begin(Mode mode = CONTINUOUS_HIGH_RES_MODE) {
    (void)mode;
    return getMockBh1750State().beginResult;
  }

  float readLightLevel() { return getMockBh1750State().lux; }
};

#endif
