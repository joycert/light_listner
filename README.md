# Light Listener

Ever wanted to control a microcontroller from the cloud? Well it's really hard, because your device is probably connected to your home network. And home networks are set up to prevent you from exposing all your stuff to abuse from the public. Thank you to my internet service provider (ISP) for protecting my fridge from being hacked.

You do have a couple options to "expose" your device to outside controll, and after extensive messing with my router, ISP, and tunneling services I've found the best one is to not try to do that at all.

Instead, you can easily make any outbound connections over wifi you want. Just tell a cloud server (easily accessable via any route) what you want to happen on your microcontroller, and have the microcontroller ask the server what you told it to tell you.

In my experience, the easiest way to do this is by setting up a MQTT broker on the server and subscribing to updates from it via your microcontroller. It takes like 5 minutes to set up the broker, just ask ChatGPT how to do it or email me (ryanjoyce54@gmail.com) if you have any trouble my girlfriend (ChatGPT) can't fix for you.

The following is the code you run on the microcontroller. I suggest you try this out. Even though it only turns on and off a very small LED the feeling the first time you type a command on your computer and something happens physically is as close to that first "hello world" log as I've ever gotten.

## Description

This project implements a basic IoT device using the Seeed XIAO ESP32-S3 board. It connects to a WiFi network and subscribes to an MQTT topic to control an LED. The device listens for "on" and "off" messages to toggle the LED state.

## Hardware Requirements

- Seeed XIAO ESP32-S3 board
  I used this board, you can use any wifi-enabled microcontroller but **\*change the platformio.ini file and led pin**
- USB cable **with a data line**, some only provide power and ground, if in doubt use the nicest looking/most expensive cord you have

## Software Requirements

- VSCode
  Insatll platformIO IDE, way better than the Arduino IDE if you spend a little bit figuring it out
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
