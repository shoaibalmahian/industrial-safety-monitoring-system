#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int mq2 = 2;
int mq3 = 3;
int sound = 12;
int lightsensor = 6;
int relay = 8;
int bz1 = 9;
int bz2 = 10;
int light = 7;
int sled = 11;

unsigned long lastGasTime = 0;
unsigned long lastAlcoholTime = 0;
unsigned long lastSoundTime = 0;
unsigned long lastLightTime = 0;

void setup() {
  dht.begin();
  Serial.begin(9600);
  lcd.begin();
  pinMode(mq2, INPUT);
  pinMode(mq3, INPUT);
  pinMode(sound, INPUT);
  pinMode(lightsensor, INPUT);

  pinMode(relay, OUTPUT);
  pinMode(bz1, OUTPUT);
  pinMode(bz2, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(sled, OUTPUT);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print("humidity= ");
  Serial.print(h);
  Serial.print("%     temperature");
  Serial.print(t);
  Serial.println("c");
  lcd.setCursor(0, 0);
  lcd.print("humidity= ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("temp= ");
  lcd.print(t);
  lcd.print("C");

  // Sensor value reading
  int gas = digitalRead(mq2);
  int alcohol = digitalRead(mq3);
  int soundvalue = digitalRead(sound);
  int lightvalue = digitalRead(lightsensor);

  // MQ2 SENSOR
  if (gas == 0) {
    digitalWrite(relay, LOW);
    digitalWrite(bz1, HIGH);
    if (millis() - lastGasTime >= 1000) {
      lastGasTime = millis();
      digitalWrite(bz1, LOW);
      delay(200);
      digitalWrite(bz1, HIGH);
    }
  } else {
    digitalWrite(relay, HIGH);
    digitalWrite(bz1, LOW);
  }

  // MQ3 SENSOR
  if (alcohol == 0) {
    if (millis() - lastAlcoholTime >= 1000) {
      lastAlcoholTime = millis();
      digitalWrite(bz2, HIGH);
      delay(500);
      digitalWrite(bz2, LOW);
      delay(500);
      digitalWrite(bz2, HIGH);
    }
  } else {
    digitalWrite(bz2, LOW);
  }

  // SOUND SENSOR
  if (soundvalue == 0) {
    if (millis() - lastSoundTime >= 1000) {
      lastSoundTime = millis();
      digitalWrite(sled, HIGH);
    }
  } else {
    digitalWrite(sled, LOW);
  }

  // LIGHT SENSOR
  if (lightvalue == 0) {
    if (millis() - lastLightTime >= 1000) {
      lastLightTime = millis();
      digitalWrite(light, HIGH);
    }
  } else {
    digitalWrite(light, LOW);
  }
}
