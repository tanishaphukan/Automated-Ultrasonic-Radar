# 📡 Automated Ultrasonic Radar

> Arduino-based radar system that uses an ultrasonic sensor mounted on a servo motor to detect nearby objects and display them on a real-time radar screen using Processing IDE.

---

## What It Does

Sweeps an HC-SR04 ultrasonic sensor left and right using a servo motor, measures distances of objects in its path, and visualizes them as a live radar on a laptop screen, just like a real sonar radar.

---

## Key Features

- 🔄 180° sweep using servo motor
- 📏 Detects objects up to 40 cm range
- 💻 Real-time radar display via Processing IDE
- 🔌 Simple, low-cost Arduino Uno setup

---

## Hardware

| Component | Purpose |
|---|---|
| Arduino Uno | Main microcontroller |
| HC-SR04 | Ultrasonic distance sensing |
| Servo Motor (SG90) | Rotates sensor 0°–180° |
| USB Cable | Serial communication to laptop |

---

## Pin Connections

| Component | Arduino Pin |
|---|---|
| HC-SR04 TRIG | Pin 10 |
| HC-SR04 ECHO | Pin 11 |
| Servo Motor | Pin 12 |
| VCC (HC-SR04 & Servo) | 5V |
| GND | GND |

---

## Getting Started

### Arduino Side
1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Open `src/radar_arduino/radar_arduino.ino`
3. Upload to Arduino Uno

### Processing Side
1. Install [Processing IDE](https://processing.org/download)
2. Open `src/radar_processing/radar_processing.pde`
3. Update the COM port in the code to match your Arduino (e.g. `"COM3"`)
4. Click **Run** — radar screen will appear

---

## Output

A green radar sweep appears on screen. Detected objects show as bright green dots with distance lines — similar to a sonar display.

---

## Applications

- Obstacle detection for robotics
- Security/intrusion detection systems
- Distance mapping in enclosed spaces
- Educational demonstration of sonar principles

---

## Future Scope

360° rotation · IoT integration · Mobile app display · Multiple sensor arrays
