# 🔋 Automatic Coolant System for EV Battery

🚗 A smart, automated cooling system designed for Electric Vehicle (EV) battery management. This IoT-based solution enhances battery performance and life using temperature-controlled actuation.

---
![image](https://github.com/user-attachments/assets/4864bb60-93d5-4352-91a0-f0841f09debf)

## 🧠 Project Overview

This project implements an intelligent battery cooling system using:

- ✅ Arduino Uno R3  
- ✅ DHT11 Temperature Sensor  
- ✅ 12V DC Cooling Fan

📡 It continuously monitors the EV battery's temperature and dynamically activates the cooling fan when temperature thresholds are crossed — ensuring efficiency, longevity, and safety of the battery pack.

---

## 📦 Features

- 🔄 Real-time Temperature Monitoring  
- 🌡️ Automatic Fan Control based on Threshold  
- 🔌 Simple, Low-Cost Implementation  
- ♻️ Scalable for Real-World EV Applications

---
![Uploading image.png…]()

## 🛠️ Components Used

| Component           | Quantity | Description                          |
|---------------------|----------|--------------------------------------|
| Arduino Uno R3       | 1        | Microcontroller                      |
| DHT11 Temperature Sensor | 1    | Measures temperature & humidity      |
| 12V DC Fan           | 1        | Cools battery system                 |
| NPN Transistor / Relay | 1     | For switching fan                    |
| 12V Power Supply     | 1        | Power source for the fan             |

---

## 🔧 Working Principle

1. DHT11 reads ambient temperature near the EV battery.
2. Arduino checks if temperature > threshold (e.g., 30°C).
3. If true, it switches on the 12V fan using a relay or transistor.
4. The fan turns off automatically when temperature drops.

---

## 📁 Folder Structure

EV-Coolant-System/
├── Code/
│ └── EV_Coolant.ino
├── assets/
│ └── ev_coolant_system_diagram.png
├── README.md
└── LICENSE
