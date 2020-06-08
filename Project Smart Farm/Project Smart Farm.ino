#include <Adafruit_GFX.h>  //ประค่าของตัววัดคาวมชื้นดิน
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

#include "DHT.h"   //ประกาศค่าของตัววัดอณุหภูมิ
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int analogInPin = A0; //ประกาศขา
const int relay = 13;  //ขา Relay

int Moisture = 0;        // ตัวแปรค่า Analog
int outputValue = 0;        // ตัวแปรสำหรับ Map เพื่อคิด %

void setup(){

  Serial.begin(9600);

  pinMode(relay, OUTPUT);
  oled.begin(0x3C); // Address 0x3C for 128x32
  oled.clearDisplay();

  dht.begin();

  delay(1000);
  }

void loop(){
  
  Moisture = analogRead(analogInPin);
  outputValue = map(Moisture, 0, 1023, 100, 0);

  
  if (outputValue <= 40) {         //ตั้งค่า % ที่ต้องการจะรดน้ำต้นไม้
    digitalWrite(relay, HIGH);
  }

  else {
    digitalWrite(relay, LOW);      //จะหยุดเมื่อน้อยกว่า 40 
  }


  oled.clearDisplay();

  float t = dht.readTemperature();

  oled.setCursor(0, 0);
  oled.setTextSize(1);
  oled.setTextColor(BLACK, WHITE);
  oled.print("Moisture =");

  oled.setCursor(70, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.print(outputValue);
  

  oled.setCursor(85, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.print(" %");

  oled.setCursor(85, 20);
  oled.setTextSize(1);
  oled.print(t);
   
  oled.setCursor(115, 20);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);              // ขนาดตัวอักษร
  oled.print(" C");                 //องศา

  oled.setCursor(0, 20);
  oled.setTextSize(1);
  oled.setTextColor(BLACK, WHITE);
  oled.println("temperature =");   //=ชื่ออณุหภูมิ

  oled.display();
  delay(20000);
  
}