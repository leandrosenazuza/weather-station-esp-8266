#include "SerialReporter.h"

#include <Arduino.h>

#include "string_constants.h"

void SerialReporter::begin(uint32_t baudRate) {
  Serial.begin(baudRate);
}

void SerialReporter::printOledNotFound() {
  Serial.println(Strings::kOledNotFound);
}

void SerialReporter::printBmp180NotFound() {
  Serial.println(Strings::kBmpNotFound);
}

void SerialReporter::printBh1750NotFound() {
  Serial.println(Strings::kBh1750NotFound);
}

void SerialReporter::printReport(const WeatherSnapshot& snapshot) {
  if (snapshot.hasDhtReadingError()) {
    Serial.println(Strings::kDhtReadFailed);
    return;
  }

  Serial.print(Strings::kLabelTempDht);
  Serial.print(snapshot.dhtTemperatureCelsius);
  Serial.print(Strings::kUnitCelsius);
  Serial.print(Strings::kSerialSeparator);
  Serial.print(Strings::kLabelHumidity);
  Serial.print(snapshot.dhtHumidityPercent);
  Serial.print(Strings::kUnitPercent);
  Serial.print(Strings::kSerialSeparator);
  Serial.print(Strings::kLabelTempBmp);
  if (snapshot.isBmp180Available && !isnan(snapshot.bmpTemperatureCelsius)) {
    Serial.print(snapshot.bmpTemperatureCelsius);
    Serial.print(Strings::kUnitCelsius);
  } else {
    Serial.print(Strings::kUnavailable);
  }
  Serial.print(Strings::kSerialSeparator);
  Serial.print(Strings::kLabelPressure);
  if (snapshot.isBmp180Available && !isnan(snapshot.bmpPressureHpa)) {
    Serial.print(snapshot.bmpPressureHpa);
    Serial.print(Strings::kUnitHpa);
  } else {
    Serial.print(Strings::kUnavailable);
  }
  Serial.print(Strings::kSerialSeparator);
  Serial.print(Strings::kLabelLux);
  if (snapshot.isBh1750Available && !isnan(snapshot.bh1750Lux)) {
    Serial.println(snapshot.bh1750Lux);
  } else {
    Serial.println(Strings::kUnavailable);
  }
}
