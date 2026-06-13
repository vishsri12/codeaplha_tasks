# 🚗 Smart Parking System using ESP32

An IoT-based Smart Parking System developed using the **ESP32 DevKit V1** and simulated in **Wokwi**. This project detects vehicle entry, automatically controls a parking gate using a servo motor, and indicates parking slot availability with LEDs. It demonstrates the use of sensors, actuators, and embedded programming for smart city and automation applications.

---

## 📌 Project Overview

Finding available parking spaces is a common challenge in busy areas. This project simulates a smart parking system that can detect vehicles entering a parking area and determine whether a parking slot is occupied or available.

The system uses two ultrasonic sensors:

- **Entry Sensor** – Detects an approaching vehicle and opens the gate automatically.
- **Parking Slot Sensor** – Detects whether the parking slot is occupied.

A servo motor acts as the parking barrier, while LEDs indicate the parking status.

---

## ✨ Features

- 🚗 Automatic vehicle detection
- 🚧 Servo-controlled parking gate
- 📍 Parking slot occupancy detection
- 🟢 Green LED indicates parking available
- 🔴 Red LED indicates parking occupied
- 📟 Real-time monitoring through Serial Monitor
- 💻 Simulated using Wokwi
- ⚡ Built using PlatformIO and VS Code

---

## 🛠 Hardware Components

- ESP32 DevKit V1
- 2 × HC-SR04 Ultrasonic Sensors
- Servo Motor
- Green LED
- Red LED
- 2 × 220Ω Resistors
- Jumper Wires

---

## 🔌 Pin Configuration

| Component | ESP32 GPIO |
|-----------|------------|
| Entry Sensor TRIG | GPIO 25 |
| Entry Sensor ECHO | GPIO 34 |
| Parking Sensor TRIG | GPIO 5 |
| Parking Sensor ECHO | GPIO 18 |
| Servo Motor | GPIO 23 |
| Green LED | GPIO 26 *(or your configured pin)* |
| Red LED | GPIO 27 *(or your configured pin)* |

> **Note:** If you changed the LED pins in your code, update the table accordingly.

---

## ⚙️ How It Works

1. A vehicle approaches the parking entrance.
2. The entry ultrasonic sensor detects the vehicle.
3. The servo motor opens the gate.
4. After a short delay, the gate closes automatically.
5. The parking slot ultrasonic sensor continuously checks whether a vehicle is parked.
6. If a vehicle is detected:
   - 🔴 Red LED turns ON.
   - 🟢 Green LED turns OFF.
7. If the slot is empty:
   - 🟢 Green LED turns ON.
   - 🔴 Red LED turns OFF.
8. The Serial Monitor displays the measured distances and parking status.

---

## 📂 Project Structure

```
Smart-Parking-System/
│
├── src/
│   └── main.cpp
│
├── diagram.json
├── wokwi.toml
├── platformio.ini
└── README.md
```

---

## ▶️ Simulation

1. Open the project in **VS Code**.
2. Install the **PlatformIO** extension.
3. Open the project folder.
4. Start the Wokwi simulation.
5. Move the virtual vehicle near the ultrasonic sensors.
6. Observe the gate opening and parking status updates.

---

## 💡 Future Improvements

- 📱 Blynk IoT integration
- 📊 Cloud-based parking monitoring
- 📲 Mobile application for live parking status
- 🅿️ Multiple parking slot management
- 📺 OLED/LCD display for available spaces
- ☁️ Firebase or MQTT connectivity
- 🔔 Buzzer notifications

---

## 🎯 Learning Outcomes

Through this project, I gained practical experience with:

- ESP32 programming
- Ultrasonic distance measurement
- Servo motor control
- GPIO input/output
- Embedded C++ programming
- IoT system design
- Wokwi simulation
- PlatformIO project development

---

## 🖥 Development Environment

- **Board:** ESP32 DevKit V1
- **Framework:** Arduino
- **IDE:** Visual Studio Code
- **Extension:** PlatformIO
- **Simulator:** Wokwi
- **Language:** C++


---

## 👨‍💻 Author

**Vishesh Srivastava**

GitHub: https://github.com/vishsri12
