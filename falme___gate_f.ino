#include<Servo.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo s1;
Servo s2;
int pir1 =2; 
int pir2 =3;
int count; 
int out;
int flamepin=7;
int flamevalue;
int led=13;

void setup()
{
Serial.begin(9600);
lcd.begin();
s1.attach(9);
s2.attach(10);
pinMode(pir1,INPUT);
pinMode(pir2,INPUT);
pinMode(flamepin,INPUT );
pinMode(led,OUTPUT);


}

void loop()
{
flamevalue=digitalRead(flamepin);
  
  if(flamevalue==LOW)
  {
    digitalWrite(led,HIGH);
    delay(100);
    s2.write(270);
    delay(1000);
   
    }
    else
    {
    digitalWrite(led,LOW);
     s2.write(0);
    
    }


int detect1=digitalRead(pir1);
int detect2=digitalRead(pir2);// read status of sensor



if(detect1==HIGH)              
{
count=count+1; 

s1.write(270);
delay(1000);
}
else{
  s1.write(0);
  }
  
if(detect2==HIGH)              
{
out=out+1; 

s2.write(270);
delay(1000);
}
else{
  s2.write(0);
  }




Serial.println(count);
Serial.println(out);
lcd.setCursor(0,0);

lcd.print(count);
lcd.print("  ENTRY");


lcd.setCursor(0,1);

lcd.print (out);
lcd.print ("   EXIT");


delay(2500); 


}  
