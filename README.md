# ESP32-Car

## Overview
ESP32-Car is a project for controlling a small car using an ESP32 microcontroller. It features a web-based interface for real-time control and video streaming from an onboard camera. The project is built using PlatformIO and the Arduino framework, and is designed to run on the Upesy Wrover ESP32 board.

<img width="250" alt="cover image" src="https://github.com/user-attachments/assets/1feb3e70-05d7-4749-9327-b0fc99f6da15" />
<img width="250" alt="cover image" src="https://github.com/user-attachments/assets/4c77f30c-a44c-4376-ab1d-c6c6ef656037" />
<img width="250" alt="image" src="https://github.com/user-attachments/assets/f966a0ae-13ae-42e6-b028-b9d7aa4c02d3" />

## Features
- WiFi Access Point mode for direct connection
- Real-time camera streaming using the ESP32-CAM
- Web interface for controlling speed and direction
- Motor control via PWM channels
- SPIFFS for serving web files (HTML, CSS, JS)

## Directory Structure
- `src/` - Main source code (C++)
  - `main.cpp` - Initializes WiFi, SPIFFS, camera, and web server
  - `server.cpp/h` - Handles web server and camera streaming
  - `camera.cpp/h` - Camera configuration and setup
- `data/` - Web assets
  - `index.html` - Web interface for car control and video stream
  - `script.js` - Joystick and control logic
  - `style.css` - Web interface styling
- `platformio.ini` - PlatformIO project configuration

## Getting Started

### Hardware Requirements
- **Upesy Wrover ESP32 board** (or ESP32-CAM compatible board)
- **Motors**: 2x DC motors for left and right wheels
- **Motor driver**: Compatible with the pin configuration (pins 12, 14, 27 for left motor; pins 32, 33, 26 for right motor)
- **Camera**: ESP32-CAM module or compatible OV2640 camera
- **Power supply**: Suitable for your motors and ESP32 board
- **Chassis**: Car frame to mount all components (e.g., 3D printed or wood plate)

### Software Requirements
- **VS Code** (using PlatformIO extension)
- **Git** (for cloning the repository)

### Pin Configuration
The project uses the following pin assignments:

**Camera pins (ESP32-CAM):**
- XCLK: GPIO 21
- SIOD (SDA): GPIO 26  
- SIOC (SCL): GPIO 27
- Y9-Y2: GPIOs 35, 34, 39, 36, 19, 18, 5, 4
- VSYNC: GPIO 25
- HREF: GPIO 23
- PCLK: GPIO 22

**Motor control pins:**
- Left motor: Enable GPIO 12, IN1 GPIO 14, IN2 GPIO 27
- Right motor: Enable GPIO 32, IN1 GPIO 33, IN2 GPIO 26

### Installation & Setup

1. **Clone the repository:**
   ```bash
   git clone https://github.com/SilvaUnCompte/ESP32-Car.git
   cd ESP32-Car
   ```

2. **Install PlatformIO:**
   - Install VS Code
   - Install the PlatformIO extension
   - Or use PlatformIO Core CLI

3. **Configure WiFi settings (optional):**
   - Edit `src/main.cpp` to change WiFi credentials:
     ```cpp
     const char* ssid = "Your-Network-Name";
     const char* password = "Your-Password";
     ```

4. **Build the project:**
   - In VS Code: Use PlatformIO toolbar → Build
   - Or via CLI: `pio run`

5. **Upload filesystem (SPIFFS):**
   - Connect your ESP32 board via USB
   - In VS Code: PlatformIO → Upload File System image
   - Or via CLI: `pio run --target uploadfs`

6. **Upload firmware:**
   - Connect your ESP32 board via USB
   - In VS Code: PlatformIO → Upload
   - Or via CLI: `pio run --target upload`

### Usage
1. **Power on the ESP32 car**
2. **Connect to WiFi:**
   - Look for WiFi network: `Esp32-SacroSaint-Wifi`
   - Password: `patate12`
3. **Access web interface:**
   - Open browser and navigate to: `http://192.168.0.1`
4. **Control the car:**
   - Use the joystick interface to control speed and direction
   - View real-time camera feed on the web interface

### Troubleshooting
- **Camera not working**: Check camera module connections and pin assignments
- **Motors not responding**: Verify motor driver connections and power supply
- **Cannot connect to WiFi**: Check serial monitor for IP address and connection status
- **Web interface not loading**: Ensure SPIFFS upload was successful

## Libraries Used
- [ESP Async WebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
- [AsyncTCP](https://github.com/me-no-dev/AsyncTCP)
- [esp32-camera](https://github.com/espressif/esp32-camera)
---
#### License
[MIT License](LICENSE)

#### Author
Selyan Quesnot, aka SilvaUnCompte
