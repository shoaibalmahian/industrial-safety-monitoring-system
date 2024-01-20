#include<DHT.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
int mq2 =2;
int mq3 =3;
int sound = 12;
int lightsensor=6;
int relay= 8;
int bz1 = 9;
int bz2 = 10;
int light=7;
int sled=11;
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
  lcd.begin();
  pinMode(mq2, INPUT); 
  pinMode(mq3, INPUT);
  pinMode(sound,INPUT);
  pinMode(lightsensor,INPUT);
  
  pinMode(relay,OUTPUT);
  pinMode(bz1,OUTPUT);
  pinMode(bz2,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(sled,OUTPUT);
  
  

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
int soundvalue = digitalRead(sound);
int lightvalue = digitalRead(lightsensor);

// MQ2 SENSOR
if(gas==0)
{
  digitalWrite(relay,LOW);
  digitalWrite(bz1,HIGH);
  delay(1000);
  digitalWrite(bz1,LOW);
  delay(200);
  digitalWrite(bz1,HIGH);
  
  }
    else
    {
    digitalWrite(relay,HIGH);
    digitalWrite(bz1,LOW);
      }
//MQ3 

if(alcohol==0)
{
   digitalWrite(bz2,HIGH);
  delay(500);
  digitalWrite(bz2,LOW);
  delay(500);
  digitalWrite(bz2,HIGH);
  
  
  
  }
    else
    {
    
    digitalWrite(bz2,LOW);
   
      }

      
//SOUND SENSOR
if(soundvalue==0)
{
   digitalWrite(sled,HIGH);
  delay(1000);
  
  
  }
    else
    {
    
    digitalWrite(sled,LOW);
      }


if(lightvalue==0)

{
   digitalWrite(light,HIGH);
  delay(1000);
  
  
  }
    else
    {
    
    digitalWrite(light,LOW);
      }


 
 
}
