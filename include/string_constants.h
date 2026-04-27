#ifndef STRING_CONSTANTS_H
#define STRING_CONSTANTS_H

namespace Strings {
constexpr const char* kOledNotFound = "OLED not found";
constexpr const char* kTitleWeatherStation = "Weather Station";
constexpr const char* kStatusStarting = "Starting...";
constexpr const char* kTitleDevice = "Medidor do Pituco";
constexpr const char* kReadError = "Erro ao ler!!!";
constexpr const char* kDhtReadFailed = "Failed to read from DHT11";
constexpr const char* kBmpNotFound = "BMP180 nao encontrado";
constexpr const char* kBh1750NotFound = "BH1750 nao encontrado";
constexpr const char* kLabelTempDht = "Temp DHT: ";
constexpr const char* kLabelHumidity = "Humidade: ";
constexpr const char* kLabelTempBmp = "Temp BMP: ";
constexpr const char* kLabelPressure = "Pressao: ";
constexpr const char* kLabelLux = "Lux: ";
constexpr const char* kUnitCelsius = " C";
constexpr const char* kUnitPercent = "%";
constexpr const char* kUnitHpa = " hPa";
constexpr const char* kUnavailable = "indisponivel";
constexpr const char* kUnavailableTempBmp = "Temp BMP: indisponivel";
constexpr const char* kUnavailablePressure = "Pressao: indisponivel";
constexpr const char* kUnavailableLux = "Lux: indisponivel";
constexpr const char* kSerialSeparator = " | ";
}

#endif
