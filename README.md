# Safe House – IoT-Based Home Security and Fire Monitoring System

Safe House is an Arduino-based IoT project designed to enhance home security and fire safety. It uses sensors to detect motion and flames and responds by controlling doors, windows, and an extinguisher through servo motors. The system is controlled remotely using a custom-built MIT App Inventor mobile app via Bluetooth.

---

## Objective

To develop a smart, responsive, and low-cost home monitoring system that:
- Detects unauthorized motion
- Identifies fire hazards early
- Controls doors, windows, fans, and extinguishers automatically
- Allows remote control via Bluetooth using a mobile app

---

## Components Used

| Component               | Specs                                     | Qty |
|------------------------|-------------------------------------------|-----|
| Arduino Uno            | ATmega328P, 5V, 14 Digital I/O            | 2   |
| Flame Sensor           | 3.3–5V, IR Flame Detection                 | 1   |
| PIR Motion Sensor      | 5V, up to 7 meters range                  | 1   |
| Servo Motors           | 5V, Torque: 1.8 kg-cm                     | 3   |
| HC-05 Bluetooth Module | Bluetooth 2.0, 10 meters range            | 1   |
| L298N Motor Driver     | 5–35V, 2A peak current                    | 1   |
| Jumper Wires           | -                                         | ✔️  |

---

## System Design

- **Flame detected** → window, door, extinguisher open automatically.
- **Motion detected** → door opens for entry.
- Bluetooth connection via HC-05 enables mobile app control.
- Commands like “open door” or “activate fan” are sent from the app and received by Arduino.
- App shows real-time updates like “Motion detected” or “Fire detected.”

---

## Mobile App (MIT App Inventor)

- Login screen for secure access.
- Real-time control panel to:
  - Open/close doors & windows
  - Activate fan or extinguisher
- Displays sensor data in real time.
- Bluetooth scanning and connection control.

---

## Features

- Dual-sensor based trigger system (Flame + PIR).
- Fully wireless control using MIT App.
- Real-time feedback via Bluetooth communication.
- Safety automation with servo-based mechanical movement.

---

## Problems Faced & Solutions

| Problem | Solution |
|--------|----------|
| Arduino underpowered with multiple motors | Added 9V external battery |
| Incorrect sensor voltage damaged Arduino | Replaced Arduino and corrected power |
| Motors not responding together | Used separate power sources |
| Bluetooth connection issues | Resolved with proper configuration via tutorials |

---

## Future Scope

- Upgrade to Wi-Fi/cloud for long-range access.
- Add voice control and facial recognition.
- Integrate real-time data logging & analytics.
- Enhance UI/UX with mobile/web dashboards.

---

## Conclusion

Safe House is a compact, smart, and responsive home security system using affordable components. It lays the foundation for more advanced, scalable smart home solutions with real-time control and environmental safety at its core.
---

## 💡 Made by:
**Chebrolu Rishita**
**Chandan Sai Pavan Padala**  
**Chivukula Vedajnaa Aparna**
Dept. of Electronics and Communication Engineering  
Amrita Vishwa Vidyapeetham, Bengaluru Campus
