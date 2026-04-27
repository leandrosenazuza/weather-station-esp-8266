#include <unity.h>

#include "Bh1750Sensor.h"
#include "Bmp180Sensor.h"
#include "Dht11Sensor.h"
#include "WeatherSnapshot.h"

namespace {
void resetMockStates() {
  getMockDhtState().humidity = NAN;
  getMockDhtState().temperature = NAN;

  getMockBmp180State().beginResult = true;
  getMockBmp180State().temperature = 0.0f;
  getMockBmp180State().pressurePa = 0;

  getMockBh1750State().beginResult = true;
  getMockBh1750State().lux = 0.0f;
}
}

void setUp() { resetMockStates(); }

void tearDown() {}

void test_Dht11Sensor_read_populates_snapshot_fields() {
  Dht11Sensor sensor(12, DHT11);
  WeatherSnapshot snapshot;

  getMockDhtState().humidity = 61.5f;
  getMockDhtState().temperature = 27.3f;

  sensor.begin();
  sensor.read(snapshot);

  TEST_ASSERT_FLOAT_WITHIN(0.001f, 61.5f, snapshot.dhtHumidityPercent);
  TEST_ASSERT_FLOAT_WITHIN(0.001f, 27.3f, snapshot.dhtTemperatureCelsius);
}

void test_Bmp180Sensor_begin_false_sets_unavailable_and_nan() {
  Bmp180Sensor sensor;
  WeatherSnapshot snapshot;

  getMockBmp180State().beginResult = false;
  getMockBmp180State().temperature = 22.2f;
  getMockBmp180State().pressurePa = 101234;

  TEST_ASSERT_FALSE(sensor.begin());
  sensor.read(snapshot);

  TEST_ASSERT_FALSE(snapshot.isBmp180Available);
  TEST_ASSERT_TRUE(isnan(snapshot.bmpTemperatureCelsius));
  TEST_ASSERT_TRUE(isnan(snapshot.bmpPressureHpa));
}

void test_Bmp180Sensor_begin_true_sets_available_and_values() {
  Bmp180Sensor sensor;
  WeatherSnapshot snapshot;

  getMockBmp180State().beginResult = true;
  getMockBmp180State().temperature = 24.8f;
  getMockBmp180State().pressurePa = 100950;

  TEST_ASSERT_TRUE(sensor.begin());
  sensor.read(snapshot);

  TEST_ASSERT_TRUE(snapshot.isBmp180Available);
  TEST_ASSERT_FLOAT_WITHIN(0.001f, 24.8f, snapshot.bmpTemperatureCelsius);
  TEST_ASSERT_FLOAT_WITHIN(0.001f, 1009.5f, snapshot.bmpPressureHpa);
}

void test_Bh1750Sensor_begin_false_sets_unavailable_and_nan() {
  Bh1750Sensor sensor;
  WeatherSnapshot snapshot;

  getMockBh1750State().beginResult = false;
  getMockBh1750State().lux = 321.0f;

  TEST_ASSERT_FALSE(sensor.begin());
  sensor.read(snapshot);

  TEST_ASSERT_FALSE(snapshot.isBh1750Available);
  TEST_ASSERT_TRUE(isnan(snapshot.bh1750Lux));
}

void test_Bh1750Sensor_begin_true_sets_available_and_lux() {
  Bh1750Sensor sensor;
  WeatherSnapshot snapshot;

  getMockBh1750State().beginResult = true;
  getMockBh1750State().lux = 456.7f;

  TEST_ASSERT_TRUE(sensor.begin());
  sensor.read(snapshot);

  TEST_ASSERT_TRUE(snapshot.isBh1750Available);
  TEST_ASSERT_FLOAT_WITHIN(0.001f, 456.7f, snapshot.bh1750Lux);
}

void test_AllThreeSensors_required_contract() {
  Dht11Sensor dhtSensor(12, DHT11);
  Bmp180Sensor bmpSensor;
  Bh1750Sensor luxSensor;
  WeatherSnapshot snapshot;

  getMockDhtState().humidity = 52.0f;
  getMockDhtState().temperature = 26.0f;
  getMockBmp180State().beginResult = true;
  getMockBmp180State().temperature = 25.4f;
  getMockBmp180State().pressurePa = 100200;
  getMockBh1750State().beginResult = false;  // Force one required sensor to fail
  getMockBh1750State().lux = 700.0f;

  dhtSensor.begin();
  bmpSensor.begin();
  luxSensor.begin();
  dhtSensor.read(snapshot);
  bmpSensor.read(snapshot);
  luxSensor.read(snapshot);

  TEST_ASSERT_FALSE(snapshot.allRequiredSensorsReady());
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_Dht11Sensor_read_populates_snapshot_fields);
  RUN_TEST(test_Bmp180Sensor_begin_false_sets_unavailable_and_nan);
  RUN_TEST(test_Bmp180Sensor_begin_true_sets_available_and_values);
  RUN_TEST(test_Bh1750Sensor_begin_false_sets_unavailable_and_nan);
  RUN_TEST(test_Bh1750Sensor_begin_true_sets_available_and_lux);
  RUN_TEST(test_AllThreeSensors_required_contract);
  return UNITY_END();
}
