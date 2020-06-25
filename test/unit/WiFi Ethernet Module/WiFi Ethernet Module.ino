#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "4KEQt6TstCkNDUeNPmI8Z834CSjNzlPc";
char ssid[] = "Thanyakorn_3BB";
char pass[] = "0962539503";

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(3, 2); // RX, TX

#define ESP8266_BAUD 96000
ESP8266 wifi(&EspSerial);

WidgetTerminal Terminal(V0);

void setup() {
  Serial.begin(9600);

  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);

  Terminal.clear();
  Terminal.println("Wifi Connected");
  Terminal.flush();
}

int i = 0;

void loop() {
  Blynk.run();
}