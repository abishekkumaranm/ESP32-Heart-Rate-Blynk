
# ESP32 Heart Rate Monitoring using MAX30102 and Blynk

## Overview

This project measures heart rate using a MAX30102 sensor connected to an ESP32. The measured BPM is transmitted over Wi-Fi to the Blynk Cloud and displayed on a live dashboard.

## Components

- ESP32 Dev Module
- MAX30102 Heart Rate Sensor
- Wi-Fi
- Blynk IoT

## Features

- Real-time Heart Rate Monitoring
- Live BPM Gauge
- Heart Rate Status
- Cloud Dashboard
- Serial Monitor Output

## Wiring

| MAX30102 | ESP32 |
|----------|-------|
| VIN | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

## Software

- Arduino IDE
- ESP32 Board Package
- Blynk Library
- SparkFun MAX3010x Library

## Dashboard

- Gauge
- Label
- Chart

## Author

Abishek Kumaran M
