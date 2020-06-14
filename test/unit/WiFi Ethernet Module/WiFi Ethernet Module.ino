
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>

SimpleTimer timer;

char auth[] = "b43150e095a142c7865e3c9cccd52777";

char ssid[] = "Thanyakorn";
char pass[] = "1234567890";

BLYNK_CONNECTED() {
    Blynk.syncAll();
}

void setup()
{
  
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
  timer.run();
}

