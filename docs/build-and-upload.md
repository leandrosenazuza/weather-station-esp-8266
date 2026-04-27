# Build and Upload Workflow

## Prerequisites
- VS Code
- PlatformIO IDE extension
- ESP8266 board connected by USB

## Build
1. Open project root in VS Code.
2. Confirm `platformio.ini` environment (`nodemcuv2` by default).
3. Run `PlatformIO: Build` (check mark icon).

## Upload
1. Connect board and select the serial port in PlatformIO.
2. Run `PlatformIO: Upload` (right arrow icon).
3. Wait for upload success message.

## Serial Monitor
1. Open monitor with `PlatformIO: Monitor`.
2. Keep monitor speed at `115200`.
3. Validate telemetry output and sensor availability messages.

## Notes
- If your board is not NodeMCU v2, update `board` in `platformio.ini`.
- Keep monitor speed aligned with `HardwareConfig::kSerialBaudRate`.
