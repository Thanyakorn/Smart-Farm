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
  pinMode(2, INPUT_PULLUP);

  oled.begin(0x3C); // Address 0x3C for 128x32

  oled.clearDisplay();

  oled.setCursor(0, 0);

  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.print("text 1");

  oled.setTextSize(2);
  oled.println("text 2");

  oled.setTextSize(3);
  oled.println("text 3");

  oled.setTextSize(1);
  oled.println("Hello World");

  oled.display();

  delay(2000);
}

void loop() {
  oled.clearDisplay();
  oled.setCursor(0, 0);

  if (!digitalRead(2)) {
    oled.println("HI 0,0");
  }

  oled.setCursor(64, 16);
  oled.println("HI 64, 16");
  oled.println(millis());

  oled.drawLine(0, 0, 32, 32, SSD1306_WHITE);

  oled.drawCircle(0, 0, 20, SSD1306_WHITE);
  oled.drawRect(32, 0, 20, 20, SSD1306_WHITE);

  oled.fillCircle(64, 0, 10, SSD1306_WHITE);
  oled.fillRect(96, 0, 20, 10, SSD1306_WHITE);

  oled.display();
  delay(10);
}
