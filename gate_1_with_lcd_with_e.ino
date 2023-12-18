#include<Servo.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo s1;
int pir =7;
int count; 

void setup()
{
Serial.begin(9600);
lcd.begin();
s1.attach(9);
pinMode(pir,INPUT);


}

void loop()
{
int detect=digitalRead(pir);   // read status of sensor
if(detect==HIGH)               // if sensor detects obstacle
{
count=count+1; 

s1.write(270);
delay(1000);
}
else{
  s1.write(0);
  }

delay(2000);
Serial.println(count);
lcd.setCursor(0,0);

lcd.print(count);


lcd.setCursor(0,1);

lcd.print ("MAHIAN SHERA");

}  
