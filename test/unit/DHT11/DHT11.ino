#include "DHT.h"   //ประกาศค่าของตัววัดอณุหภูมิ
#define DHTPIN 2   //ขา2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup(){

    Serial.begin(9600);
    dht.begin();


}

void loop(){

    float t = dht.readTemperature();
    Serial.print("temperature = ");
    Serial.print(t);
    Serial.println(" *C");  
    delay(1000);

  
}