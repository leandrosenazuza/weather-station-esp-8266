#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

#include <Arduino.h>
#include <DHT.h>

namespace HardwareConfig {
constexpr uint8_t kDisplayScreenWidth = 128;
constexpr uint8_t kDisplayScreenHeight = 64;
constexpr int8_t kDisplayOledResetPin = -1;
constexpr uint8_t kOledI2cAddress = 0x3C;

constexpr uint32_t kSerialBaudRate = 115200;
constexpr uint16_t kStartupSplashDelayMs = 1500;
constexpr uint16_t kMainLoopDelayMs = 20000;

// DHT11 sensor (air temperature and humidity).
constexpr uint8_t kDht11DataGpio = 12;  // D6
constexpr uint8_t kDht11SensorType = DHT11;

// OLED I2C bus (local data display).
constexpr uint8_t kOledI2cSdaGpio = 4;  // D2
constexpr uint8_t kOledI2cSclGpio = 5;  // D1

// BMP180 I2C bus (temperature and atmospheric pressure).
constexpr uint8_t kBmp180I2cSdaGpio = 4;
constexpr uint8_t kBmp180I2cSclGpio = 5;

// BH1750 I2C bus (ambient light in lux).
constexpr uint8_t kBh1750I2cSdaGpio = 4;
constexpr uint8_t kBh1750I2cSclGpio = 5;
}

#endif
