# Safe House – IoT-Based Home Security and Fire Monitoring System

> An intelligent, responsive, and cost-effective home automation system designed to enhance residential security and fire safety through automated hazard detection and remote control.

---

## Overview

Safe House is an Arduino-based Internet of Things (IoT) project engineered to provide real-time home monitoring. Utilizing a specialized dual-sensor network, the system proactively detects unauthorized intrusions and fire hazards. Upon detection, it autonomously triggers safety protocols—such as opening doors and windows or deploying an extinguisher via servo motors. Additionally, the system features seamless wireless control through a custom-built mobile application communicating over Bluetooth, enabling users to monitor and manage their home environment remotely.

## Key Features

- **Automated Hazard Response:** Dual-sensor network (PIR for motion, IR for flame) triggers immediate mechanical actions to mitigate emergencies.
- **Wireless Mobile Control:** Custom Android application built with MIT App Inventor for secure, real-time system management.
- **Real-Time Telemetry:** Instant feedback on environmental status ("Motion Detected", "Fire Detected") transmitted via Bluetooth.
- **Safety Automation:** Servo-driven mechanical systems automatically open emergency exits and activate countermeasures in crisis scenarios.

## Hardware Architecture

The core of the system relies on an optimized interplay of microcontrollers, sensors, and actuators.

| Component | Specifications | Quantity | Purpose |
|---|---|:---:|---|
| **Arduino Uno** | ATmega328P, 5V, 14 Digital I/O | 2 | Primary microcontrollers for sensor processing and motor control. |
| **Flame Sensor** | 3.3–5V, IR Flame Detection | 1 | Detects fire outbreaks for immediate response. |
| **PIR Sensor** | 5V, up to 7 meters range | 1 | Detects unauthorized motion within the premises. |
| **Servo Motors** | 5V, Torque: 1.8 kg-cm | 3 | Actuates doors, windows, and fire extinguisher mechanisms. |
| **HC-05 Module** | Bluetooth 2.0, 10 meters range | 1 | Facilitates wireless communication with the mobile app. |
| **L298N Driver** | 5–35V, 2A peak current | 1 | Controls high-power actuator movement. |

![System Prototype](https://github.com/user-attachments/assets/ed0ab535-5fbd-4fd5-82ec-f913b5754c27)

## Software Architecture & Mobile Interface

A custom-built Android application serves as the primary user interface, ensuring secure and intuitive control over the Safe House system.

- **Secure Access:** Built-in authentication mechanism for restricted entry.
- **Live Command Dashboard:** Manually override or control actuators (doors, windows, fans).
- **Real-Time Data Feed:** Live sensor metrics and emergency alerts pushed directly to the dashboard.
- **Bluetooth Management:** Integrated scanning, pairing, and connection management for the HC-05 module.

## System Workflow

1. **Environmental Monitoring:** Sensors continuously scan the environment. 
2. **Crisis Detection:**
   - *Fire Scenario:* The flame sensor triggers the system to open windows for ventilation, unlock the emergency door, and deploy the extinguisher mechanism.
   - *Intrusion Scenario:* The PIR sensor detects motion, triggering the main door to lock/unlock depending on the security mode, and sending an alert to the mobile app.
3. **Remote Override:** The user sends explicit commands (e.g., "Open Door") from the app, which are parsed by the Arduino to drive the respective servos.

## Challenges & Technical Resolutions

During the development lifecycle, several hardware constraints were addressed:

| Challenge | Technical Resolution |
|---|---|
| **Power Constraints:** Arduino rebooting under heavy motor load. | Decoupled the logic and actuator power supplies; integrated an external 9V source specifically for the servo array. |
| **Voltage Mismatches:** Component damage due to incorrect logic levels. | Standardized operating voltages and replaced compromised microcontrollers; implemented proper voltage division. |
| **Actuator Synchronization:** Servos stalling when activated concurrently. | Restructured the power distribution network to provide parallel current paths from a dedicated power source. |
| **Telemetry Latency:** Unstable Bluetooth pairing and packet drops. | Reconfigured HC-05 baud rates and optimized the serial communication protocol to ensure reliable packet delivery. |

## Future Scope

- **IoT Cloud Integration:** Transition from Bluetooth to Wi-Fi (e.g., ESP32/ESP8266) for global accessibility and cloud data logging.
- **Advanced Machine Learning:** Implement facial recognition for authorized access and anomaly detection.
- **Comprehensive Dashboards:** Develop full-scale web and mobile dashboards with historical data analytics.
- **Voice Capabilities:** Integration with smart home ecosystems such as Amazon Alexa or Google Home.

## Conclusion

Safe House demonstrates a compact, smart, and responsive home security system using affordable components. It lays a strong technical foundation for more advanced, scalable smart home solutions with real-time remote control and environmental safety at its core.

---

## Authors

- **Chandan Sai Pavan Padala**
- **Chivukula Vedajnaa Aparna**
- **Chebrolu Rishita**

**Department of Electronics and Communication Engineering**  
*Amrita Vishwa Vidyapeetham, Bengaluru Campus*
