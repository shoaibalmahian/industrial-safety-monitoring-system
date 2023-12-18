#include<Servo.h>
Servo s1;
int pir =7;
int count;

void setup()
{
Serial.begin(9600);
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
delay(1000);// led on
          // buzzer sounds
}
else{
  s1.write(0);
  }

delay(300);
Serial.println(count);
delay(1000);
}  
