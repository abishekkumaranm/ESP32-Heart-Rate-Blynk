#define BLYNK_TEMPLATE_ID "TMPL3F5U5QLX6"
#define BLYNK_TEMPLATE_NAME "heart rate"
#define BLYNK_AUTH_TOKEN "d29YO0SxQzdzAWgOFz3FF6V4AppKo_jI"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

char ssid[] = "Janani";
char pass[] = "12345698";

MAX30105 particleSensor;

long lastBeat = 0;
float bpm = 0;
int beatAvg = 0;

BlynkTimer timer;

void sendData()
{
  Blynk.virtualWrite(V0, beatAvg);

  if (beatAvg < 60)
  {
    Blynk.virtualWrite(V1, "Low BPM");
  }
  else if (beatAvg > 100)
  {
    Blynk.virtualWrite(V1, "High BPM");
  }
  else
  {
    Blynk.virtualWrite(V1, "Normal");
  }
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Wire.begin(21, 22);

  Serial.println("Initializing MAX30102...");

  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD))
  {
    Serial.println("MAX30102 not found!");
    while (1);
  }

  particleSensor.setup();
  particleSensor.setPulseAmplitudeRed(0x0A);
  particleSensor.setPulseAmplitudeGreen(0);

  timer.setInterval(2000L, sendData);

  Serial.println("Place your finger on the sensor.");
}

void loop()
{
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue))
  {
    long delta = millis() - lastBeat;
    lastBeat = millis();

    bpm = 60.0 / (delta / 1000.0);

    if (bpm > 40 && bpm < 180)
    {
      beatAvg = (int)bpm;

      Serial.print("BPM: ");
      Serial.println(beatAvg);
    }
  }

  Blynk.run();
  timer.run();
}