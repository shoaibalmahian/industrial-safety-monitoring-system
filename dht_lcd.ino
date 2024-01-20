#include<DHT.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
  lcd.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
float t = dht.readTemperature();
float h = dht.readHumidity();
Serial.print("humidity= ");
Serial.print(h);
Serial.print("%     temperature");
Serial.print(t);
Serial.println("c");
lcd.setCursor(0,0);

lcd.print("humidity= ");
lcd.print(h);
lcd.print("%");



lcd.setCursor(0,1);

lcd.print ("temp= ");
lcd.print (t);
lcd.print ("C");



delay(2000);


}
