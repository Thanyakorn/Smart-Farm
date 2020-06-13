#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



// SET Timer
SimpleTimer timer;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b43150e095a142c7865e3c9cccd52777";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "gieow";
char pass[] = "1234567890";

BLYNK_CONNECTED() {
    Blynk.syncAll();
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
  timer.setInterval(4000L, sendTemp);
}

void sendTemp()
{
  float temperature = 0;
  float humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(pinDHT22, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err="); Serial.println(err);delay(2000);
    return;
  }  
  Blynk.virtualWrite(10, temperature); // virtual pin 
  Blynk.virtualWrite(11, humidity); // virtual pin 
}

void loop()
{
  Blynk.run();
  timer.run();
}

