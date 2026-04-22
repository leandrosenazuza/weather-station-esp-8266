#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT11 data pin on D5 (GPIO14).
#define DHTPIN 4 //No ESP8266, esse eh o pino D2
#define OLED_SDA 12 //No ESP8266, esse eh o pino D6
#define OLED_SCL 14 //No ESP8266, esse eh o pino D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    while (true) {
      delay(1000);
    }
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Weather Station"));
  display.println(F("Starting..."));
  display.display();
  delay(1500);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Medidor do Pituco"));

  if (isnan(h) || isnan(t)) {
    display.println(F("Erro ao ler!!!"));
    Serial.println(F("Failed to read from DHT11"));
  } else {
    display.setTextSize(2);
    display.setCursor(0, 18);
    display.print(t, 1);
    display.println(F(" oC"));

    display.setTextSize(1);
    display.setCursor(0, 50);
    display.print(F("Humidade: "));
    display.print(h, 0);
    display.println(F("%"));

    Serial.print(F("Tem: "));
    Serial.print(t);
    Serial.print(F(" C | Humidade: "));
    Serial.print(h);
    Serial.println(F("%"));
  }

  display.display();
  delay(2000);
}