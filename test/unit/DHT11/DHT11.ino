#include "DHT.h"   //ประกาศค่าของตัววัดอณุหภูมิ
#define DHTPIN 2   //ขา2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int analogInPin = A0; //ประกาศขา
int Moisture = 0;        // ตัวแปรค่า Analog
int outputValue = 0;        // ตัวแปรสำหรับ Map เพื่อคิด %

void setup(){

    Serial.begin(9600);


}

void loop(){

  Moisture = analogRead(analogInPin);
  outputValue = map(Moisture, 0, 1023, 100, 0); //คิดเป็น %


  Serial.print("Moisture = ");
  Serial.print(outputValue);
  Serial.println(" %");

  delay(1000);





}