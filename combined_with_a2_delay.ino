#include<DHT.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
int mq2 =2;
int mq3 =3;
int relay= 8;
int bz1 = 9;
int bz2 = 10;

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
  lcd.begin();
  pinMode(mq2, INPUT); 
  pinMode(mq3, INPUT);
  pinMode(relay,OUTPUT);
  pinMode(bz1,OUTPUT);
  pinMode(bz2,OUTPUT);
  

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
// sensor value reading
int gas  = digitalRead(mq2); 
int alcohol  = digitalRead(mq3);
// MQ2 SENSOR
if(gas==0)
{
  digitalWrite(relay,LOW);
  digitalWrite(bz1,HIGH);
  delay(1000);
  
  }
    else
    {
    digitalWrite(relay,HIGH);
    digitalWrite(bz1,LOW);
      }
if(alcohol==0)
{
   digitalWrite(bz2,HIGH);
  delay(1000);
  
  
  }
    else
    {
    
    digitalWrite(bz2,LOW);
      }



delay(2000);


}
