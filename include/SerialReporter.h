#ifndef SERIAL_REPORTER_H
#define SERIAL_REPORTER_H

#include "WeatherSnapshot.h"

class SerialReporter {
public:
  void begin(uint32_t baudRate);

  void printOledNotFound();
  void printBmp180NotFound();
  void printBh1750NotFound();
  void printReport(const WeatherSnapshot& snapshot);
};

#endif
