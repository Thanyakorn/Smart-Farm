const int analogInPin = A0; //ประกาศขา
int Moisture = 0;        // ตัวแปรค่า Analog
int outputValue = 0;        // ตัวแปรสำหรับ Map เพื่อคิด %

void setup(){

    Serial.begin(9600);


}

void loop(){

  

Moisture = analogRead(analogInPin);

  Serial.print("Moisture = ");
  Serial.print(Moisture);
  Serial.println(" %");

  delay(1000);






}