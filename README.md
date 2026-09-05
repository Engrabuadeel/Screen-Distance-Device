
# Screen Distance Device

An Arduino-based ergonomic desktop device that actively monitors your seating posture to protect your eyes and spine. Using an ultrasonic sensor, it tracks your real-time distance from the laptop screen. If you lean in too close (under the 40 cm safety threshold), a piezo buzzer triggers an audio alarm to remind you to sit back, while a live distance feed is displayed on an OLED screen.


## 🚀 Features
* **Real-Time Distance Tracking:** Highly responsive distance measurement using an HC-SR04 sensor.
* **Visual Feedback:** Live distance readout in centimeters on a compact 128x32 I2C OLED display.
* **Auditory Posture Alarm:** Piezo buzzer emits a 1000 Hz warning tone when the user breaches the safe ergonomic distance.
* **Adjustable Thresholds:** Safety distance can be easily recalibrated in the code for different desk setups.

## 🛠️ Hardware Requirements
* Arduino Uno (or Arduino Nano for a permanent setup)
* HC-SR04 Ultrasonic Distance Sensor
* 0.91" I2C OLED Display (SSD1306 128x32)
* Piezo Buzzer (Passive)
* Jumper Wires & Breadboard
* USB Cable (for continuous laptop power)

## 🔌 Wiring Schematic

![Uploading CircuitDiag.png…]()


| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **HC-SR04** | VCC | 5V |
| | GND | GND |
| | Trig | D8 |
| | Echo | D9 |
| **OLED (I2C)**| VCC | 5V |
| | GND | GND |
| | SDA | A4 |
| | SCL | A5 |
| **Piezo Buzzer**| Positive (Long Leg) | D10 |
| | Negative (Short Leg) | GND |

## 💻 Software & Libraries
This project is written in C++ using the Arduino IDE. You will need to install the following libraries via the Library Manager:
* `Wire.h` (Built-in)
* `Adafruit_GFX.h`
* `Adafruit_SSD1306.h`

## ⚙️ Installation & Usage
1. Assemble the hardware on a breadboard according to the wiring table and circuit diagram.
2. Connect the Arduino to your laptop via USB.
3. Open the `.ino` file in the Arduino IDE.
4. Adjust the `#define SAFE_DISTANCE 40` variable if you prefer a different trigger distance.
5. Compile and upload the code to your Arduino.
6. Place the sensor on your laptop bezel facing you—the monitor is now active!


