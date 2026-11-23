# Smart Grid Heatwave Controller (IoT + AI)

**NxtWave IdeaForge Hackathon** | Built by **M Sai Varshini**

---

## The Problem
During peak summers in India, extreme heatwaves and water shortages hit at the same time and put a lot of pressure on city power and water systems. Power substations and electrical grids start overheating once temperatures cross 35°C, which can damage equipment or cause sudden power cuts. At the same time, water tank levels drop fast and often go unnoticed until they are almost empty. Most of this is still checked manually, so control room staff react late, people don't get alerts on time, and there is no automatic record of past emergencies.

---

## What I Built
I built a two-part system that connects an ESP32 hardware simulation in **Wokwi** with a **Gemini AI** control center in **Google Colab**:

1. **Hardware Simulation (Wokwi):** Monitors temperature and water tank levels every 2 seconds, triggers local LED alerts automatically, and prints a live status report in the Serial Monitor.
2. **AI Control Center (Google Colab + Gemini):** Status reports from Wokwi are copied and pasted into Colab. Gemini checks the readings, marks the situation as **Safe**, **Warning**, or **Critical** with the current IST time, gives 3 clear steps for the control room operator, writes a short citizen alert, and saves every report into `incident_log.txt`.

---

## Hardware & Alert Logic

| Component | What it does | Trigger |
| :--- | :--- | :--- |
| **ESP32** | Main microcontroller | Checks sensors every 2 seconds |
| **DHT22 Sensor** | Reads temperature | Triggers cooling fan at **35°C or above** |
| **Potentiometer** | Simulates water tank level (0–100%) | Triggers water alert at **40% or below** |
| **🔴 Red LED** | Cooling Fan indicator | Turns **ON** when Temp ≥ 35°C |
| **🔵 Blue LED** | Water Shortage alert | Turns **ON** when Water ≤ 40% |

---

## Files in this Repo
- `wokwi_esp32_controller.ino` — ESP32 code for Wokwi to read the sensors, control the LEDs, and print status reports.
- `ai_control_center.py` — Python code (run in Google Colab) that uses the Gemini API to analyze reports and generate alerts.
- `incident_log.txt` — Sample saved reports from the system for audit records.

---

## Tech Stack
- **IoT Simulation:** Wokwi (ESP32, DHT22, Potentiometer, LEDs, Arduino C++)
- **AI Control Center:** Python, Google Colab, Google Gemini API

---

## Hardware Pin Connections (ESP32)
You can test the pre-wired simulation directly here: **[Launch Live Wokwi Simulation](https://wokwi.com/projects/480749792600160257)**

| Component | ESP32 Pin | Purpose |
| :--- | :--- | :--- |
| **DHT22 Sensor (SDA/Data)** | GPIO 15 | Reads live ambient temperature |
| **Potentiometer (SIG)** | GPIO 34 | Simulates reservoir water level (0–100%) |
| **Red LED** | GPIO 2 | Cooling fan alert (ON at ≥ 35°C) |
| **Blue LED** | GPIO 4 | Low water alert (ON at ≤ 40%) |

---

## How to Run It
1. Open `wokwi_esp32_controller.ino` in Wokwi with an ESP32, DHT22 sensor, potentiometer, and two LEDs, then click **Play**.
2. Open the Python code in Google Colab, add your `GEMINI_API_KEY` in the **Secrets** tab on the left, and run it.
3. Copy any status report from the Wokwi Serial Monitor and paste it into the Colab prompt to get the full control room report.
4. Type `exit` when you want to stop. All generated reports are saved in `incident_log.txt`.

---

## System Previews

### Wokwi ESP32 Simulation
<img width="2940" height="1596" alt="image" src="https://github.com/user-attachments/assets/98f908d1-28f2-4a07-8c74-be454a80519e" />



### Gemini AI Control Center Output
<img width="2570" height="820" alt="image" src="https://github.com/user-attachments/assets/5cd2c6aa-37c2-4980-bb0d-8aa6e32e1483" />


---

## ⚡ From Simulation to Substation
- **Automated Data Transfer:** Replace the manual copy-paste step by reading live sensor data directly over a **USB Serial** connection (using Python) or syncing it wirelessly through a cloud database like **Firebase**.
- **Real Hardware Controls:** Swap the LED indicators for **relay modules** to automatically switch real substation cooling fans and water pumps on and off.
- **Direct Citizen Alerts:** Connect an SMS or WhatsApp API so Gemini's citizen warnings are sent straight to people's phones alongside being saved in `incident_log.txt`.

---

© 2026 **M Sai Varshini**. All rights reserved.  
Built for the **NxtWave IdeaForge Hackathon**.
