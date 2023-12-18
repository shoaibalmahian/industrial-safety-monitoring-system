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

s1.attach(9);
pinMode(pir,INPUT);
lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Tech Trends");
  delay(2000);
  lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  lcd.print("Target Distance:");


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
 lcd.setCursor(0,1);  //Set cursor to first column of second row
  lcd.print("                "); //Print blanks to clear the row
  lcd.setCursor(0,1);   //Set Cursor again to first column of second row
  lcd.print(count); //Print measured distance
  lcd.print(" cm");  //Print your units.
  delay(250);
}  
