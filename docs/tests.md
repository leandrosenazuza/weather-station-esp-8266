# Sensor Unit Tests

## Scope
These tests validate the sensor classes with mocked dependencies:
- `Dht11Sensor`
- `Bmp180Sensor`
- `Bh1750Sensor`

All tests are located in `test/test_sensors/test_main.cpp`.

## How To Run
From project root:

```bash
platformio test -e native_test
```

## Expected Output
- Unity test runner starts
- All sensor tests pass
- Required-sensors contract test confirms failure when one required sensor is unavailable

## If A Test Fails
- `Dht11Sensor` failure: check DHT mapping to snapshot humidity/temperature.
- `Bmp180Sensor` failure: check `begin()` availability and pressure conversion to hPa.
- `Bh1750Sensor` failure: check `begin()` availability and lux propagation.
- Required contract failure: verify the boolean rule for all three required sensors.
