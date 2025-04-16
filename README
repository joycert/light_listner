# Light Listener

A simple IoT project that controls an LED using MQTT messages on an ESP32-S3 microcontroller.

## Description

This project implements a basic IoT device using the Seeed XIAO ESP32-S3 board. It connects to a WiFi network and subscribes to an MQTT topic to control an LED. The device listens for "on" and "off" messages to toggle the LED state.

## Hardware Requirements

- Seeed XIAO ESP32-S3 board
- LED (connected to pin 21)
- USB cable for programming and power

## Software Requirements

- PlatformIO IDE
- Arduino framework
- Required libraries:
  - PubSubClient (for MQTT communication)
  - WiFi (built-in with ESP32)

## Configuration

Before uploading the code, you need to create a `secrets.h` file in the `src` directory with the following content:

```cpp
#ifndef SECRETS_H
#define SECRETS_H

const char* WIFI_SSID = "your_wifi_ssid";
const char* WIFI_PASS = "your_wifi_password";
const char* MQTT_SERVER = "your_mqtt_broker_ip";
const char* MQTT_USER = "your_mqtt_username";
const char* MQTT_PASS = "your_mqtt_password";
const char* MQTT_TOPIC = "your_mqtt_topic";

#endif
```

## Features

- WiFi connectivity with status indication
- MQTT client implementation
- LED control via MQTT messages
- Automatic reconnection to MQTT broker
- Serial debugging output

## Usage

1. Connect the LED to pin 21 of the ESP32-S3 board
2. Configure your WiFi and MQTT credentials in `secrets.h`
3. Upload the code to the board
4. Send MQTT messages to the configured topic:
   - Send "on" to turn the LED on
   - Send "off" to turn the LED off

## Building and Uploading

1. Open the project in PlatformIO
2. Select the "seeed_xiao_esp32s3" environment
3. Click the "Upload" button

## Troubleshooting

- If the LED doesn't respond, check the MQTT connection status in the serial monitor
- Ensure the WiFi credentials are correct
- Verify the MQTT broker is accessible from your network
- Check the LED connection to pin 21

## License

This project is open source and available under the MIT License.
