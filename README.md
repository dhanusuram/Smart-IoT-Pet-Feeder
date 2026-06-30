🐾 Smart IoT Pet Feeder
📌 Project Overview

The Smart IoT Pet Feeder is an automated pet feeding system using Arduino UNO + ESP8266 + Blynk IoT platform.
It allows automatic feeding based on schedule and also manual feeding using a button. It monitors pet presence using an ultrasonic sensor and provides real-time updates via mobile app.

⚙️ Features
🍖 Automatic food dispensing using Servo Motor
📡 Ultrasonic sensor for pet detection
📱 Blynk IoT mobile app integration
⏰ Scheduled feeding (Morning / Afternoon / Night)
💡 LED indicators for reminders
📺 LCD display for time and status
🔘 Manual feeding using push button
🌐 WiFi-based remote monitoring
🧰 Components Used
Arduino UNO
ESP8266 NodeMCU
Servo Motor
Ultrasonic Sensor (HC-SR04)
16x2 I2C LCD Display
Push Button
LEDs
Jumper Wires
Power Supply
💻 Software Used
Arduino IDE
Blynk IoT App
ESP8266 Board Package
Libraries:
Servo.h
BlynkSimpleEsp8266.h
NTPClient
hd44780 LCD Library
🧠 Working Principle
User sets feeding time using Blynk App
ESP8266 syncs time using NTP Server
Arduino controls servo motor for food dispensing
Ultrasonic sensor detects pet presence
LCD shows current time and feeding status
LED indicators show active reminder periods
Data is updated in real-time to mobile app
📁 Project Structure
Smart-IoT-Pet-Feeder/
│
├── Arduino/
│   └── PetFeeder_Arduino.ino
│
├── ESP8266/
│   └── PetFeeder_ESP8266.ino
│
├── Images/
│   ├── circuit.jpg
│   ├── project.jpg
│
├── Report/
│   └── Project_Report.pdf
│
└── README.md
🚀 How to Run
Open Arduino IDE
Install required libraries
Upload Arduino code to Arduino UNO
Upload ESP8266 code to NodeMCU
Connect hardware components
Open Blynk App and configure virtual pins
Power ON system
📊 Future Improvements
📷 Camera-based pet recognition
🐕 Food level monitoring sensor
📲 Push notification alerts
🔋 Battery backup system
🎙 Voice control integration
👨‍💻 Author

Dhanusuram s
B.Sc Computer Science
Final Year Project
