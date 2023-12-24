#include<DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
float t = dht.readTemperature();
float h = dht.readHumidity(true);
Serial.print("humidity= ");
Serial.print(h);
Serial.print("%     temperature");
Serial.print(t);
Serial.println("c");
delay(2000);


}
