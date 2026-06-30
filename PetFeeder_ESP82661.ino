#define BLYNK_TEMPLATE_ID "TMPL35B-c4nCZ"
#define BLYNK_TEMPLATE_NAME "PetFeeder"
#define BLYNK_AUTH_TOKEN "_MRJKIJRiFm0drOEJg4Y7rvXhoQbKtfa"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <Wire.h>
#include <BlynkSimpleEsp8266.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

// WiFi credentials
const char *ssid = "projectiot";
const char *password = "123456789abc";

// Virtual Pin
#define VPIN_1 V7

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(VPIN_1);
}

// NTP setup
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800);

// Time variables from Blynk
int morningStartHour = -1, morningStartMinute = -1;
int morningEndHour = -1, morningEndMinute = -1;

int afternoonStartHour = -1, afternoonStartMinute = -1;
int afternoonEndHour = -1, afternoonEndMinute = -1;

int nightStartHour = -1, nightStartMinute = -1;
int nightEndHour = -1, nightEndMinute = -1;

// LCD
hd44780_I2Cexp lcd;

// LED pins
const int morningLedPin = D3;
const int afternoonLedPin = D6;
const int nightLedPin = D7;