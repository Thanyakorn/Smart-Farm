/*

INSTRALL FORM IDE LIBRARY MANAGER
- Adafruit IO
- Adafruit GFX
- Adafruit SSD1306

*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

void setup() {
  
  oled.begin(0x3C); // Address 0x3C for 128x32
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.println("Hello World");

  oled.display();

  delay(1000);
}

void loop() {
 
 
}
