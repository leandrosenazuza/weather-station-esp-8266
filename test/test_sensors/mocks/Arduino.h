#ifndef MOCK_ARDUINO_H
#define MOCK_ARDUINO_H

#include <cmath>
#include <cstdint>

using uint8_t = std::uint8_t;
using int8_t = std::int8_t;
using uint16_t = std::uint16_t;

#ifndef NAN
#define NAN std::nanf("")
#endif

using std::isnan;

#endif
