/*
  Smart IoT Pet Feeder
  Arduino UNO Program

  Components:
  - Servo Motor
  - HC-SR04 Ultrasonic Sensor
  - Push Button
  - LED

  Sends:
    '1' -> Pet detected
    '2' -> Pet not detected

  Communicates with ESP8266 through Serial.
*/

#include <Servo.h>

// -------------------------------
// Pin Definitions
// -------------------------------
#define TRIG_PIN 7
#define ECHO_PIN 6
#define BUTTON_PIN 8
#define LED_PIN 9
#define SERVO_PIN 3

#define PET_DISTANCE 15   // Distance in cm

Servo servo1;

// -------------------------------
// Setup
// -------------------------------
void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUTTON_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);

  servo1.attach(SERVO_PIN);
  servo1.write(0);

  digitalWrite(LED_PIN, LOW);
}

// -------------------------------
// Measure Distance
// -------------------------------
int getDistance()
{
  long duration;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  int distance = duration * 0.034 / 2;

  return distance;
}

// -------------------------------
// Feed Pet
// -------------------------------
void feedPet()
{
  servo1.write(180);

  digitalWrite(LED_PIN, HIGH);

  delay(1000);

  servo1.write(0);

  digitalWrite(LED_PIN, LOW);
}

// -------------------------------
// Loop
// -------------------------------
void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH)
  {
    feedPet();

    int distance = getDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < PET_DISTANCE)
    {
      Serial.write('1');      // Pet detected
    }
    else
    {
      Serial.write('2');      // Pet not detected
    }

    delay(500);
  }

  servo1.write(0);
  digitalWrite(LED_PIN, LOW);
}