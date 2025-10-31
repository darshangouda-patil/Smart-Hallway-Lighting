# Smart Hallway Lighting Automation System

### 🔦 Project Overview
The **Smart Hallway Lighting Automation System** is designed to automatically control hallway lights based on human presence.  
It detects a person entering the hallway using a **PIR sensor** and turns ON the lights one by one.  
When no motion is detected for a certain time, it turns OFF the lights in reverse order, ensuring energy efficiency and convenience.

---

### ⚙️ Features
- Automatic light activation using motion detection  
- Sequential ON/OFF of LEDs to simulate hallway lighting  
- Low power consumption  
- Simple and cost-effective implementation using Arduino Uno  

---

### 🧠 Components Used
| Component | Description |
|------------|-------------|
| **Arduino Uno** | Main microcontroller used to control the system |
| **PIR Sensor** | Detects motion of a person entering or leaving the hallway |
| **Relay Module** | Controls AC lights or higher power devices |
| **LEDs** | Simulated hallway lights (can be replaced with bulbs) |
| **Resistors & Wires** | For current limiting and circuit connections |
| **Power Supply (5V)** | To power the Arduino and peripherals |

---

### 🔌 Working Principle
1. **Detection:** PIR sensor detects motion when someone enters the hallway.  
2. **Lighting Sequence:** Arduino turns ON LEDs or relays in sequence.  
3. **Timeout:** After no motion is detected for a set time, lights turn OFF one-by-one in reverse order.  
4. **Control:** The system resets and waits for the next detection.

---

### 🧾 Code Explanation (Embedded C for Arduino)
- The PIR sensor output is read using a digital input pin.  
- LEDs or relays are controlled using digital output pins.  
- A simple delay logic manages the ON/OFF timing sequence.  

---

### 🧪 How to Use
1. Upload the `.ino` or `.c` code to your **Arduino Uno** using Arduino IDE.  
2. Connect PIR sensor and LEDs as per the circuit diagram.  
3. Power up the system — lights will turn ON when motion is detected.  
4. Observe lights turning OFF sequentially after timeout.

---

### 💡 Future Improvements
- Add light intensity control using an LDR.  
- Include IoT connectivity (ESP32/Wi-Fi module).  
- Add manual override button for control.  

---

### 👤 Author
**Darshangouda**

---

### 🖼️ Folder Structure
