# Weather Station (ESP8266)

Weather station created with ESP8266.

## Kit Contents

- 1 × ESP8266 — microcontrolador com Wi-Fi que controla todo o sistema
- 1 × ESP8266-12E — módulo do ESP8266 com mais pinos e melhor desempenho
- 1 × DHT11 — sensor de temperatura e umidade
- 1 × BMP180 — sensor de pressão atmosférica
- 1 × BH1750FVI — sensor de luminosidade (nível de luz)
- 1 × OLED Display — tela para exibir dados (clima, hora, sensores)
- 1 × USB Cable — usado para alimentação e upload do código
- 2 × Breadboards — permitem montar o circuito sem solda
- 20 × Dupont Cables — fios para conectar os componentes

## Image

<img width="300" height="300" alt="Weather Station" src="https://github.com/user-attachments/assets/5aca115d-2482-4e67-a22b-607d1c58e2e7" />

## Description

The weather station uses the **ESP8266-12E** to retrieve data from the internet, including:
- Current time for a selected city
- Weather data
- 3-day weather forecast

This information is displayed on an **SSD1306 OLED display** with scrolling support.

The device can switch between cities worldwide, allowing you to monitor weather conditions in locations where your friends or family live.

Additionally, the system uses onboard sensors to collect environmental data:
- **DHT11** – temperature and humidity
- **BMP180** – atmospheric pressure
- **BH1750FVI** – light intensity
