#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 7         // DHT11 sensor data pin
#define DHTTYPE DHT11    // DHT sensor type

#define MOTOR_PIN_ENA 9  // Enable pin for motor driver (PWM pin)
#define MOTOR_PIN_IN1 10  // Input pin 1 for motor driver
#define MOTOR_PIN_IN2 11  // Input pin 2 for motor driver

#define TEMPERATURE_THRESHOLD 29 
#define TEMPERATURE_THRESHOLD1 32 // Temperature threshold to adjust motor speed

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x3F, 16, 2);  // Adjust the I2C address if necessary

void setup() {
  Serial.begin(9600);
  dht.begin();

  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
}

void loop() {
  delay(2000); // Delay between readings (adjust as needed)

  float temperature = dht.readTemperature(); // Read temperature in Celsius
  if (isnan(temperature)) {
    Serial.println("Failed to read temperature from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  lcd.setCursor(0, 1); // Set cursor to the second line
  lcd.print("                "); // Clear the previous motor speed

  // Adjust motor speed based on temperature
  if (temperature > TEMPERATURE_THRESHOLD1) {
    // Increase motor speed
    analogWrite(MOTOR_PIN_ENA, 255);    // Set the motor speed to maximum (255)
    digitalWrite(MOTOR_PIN_IN1, HIGH);  // Set motor direction (forward)
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor Speed: Max");
  }
  else if (temperature > TEMPERATURE_THRESHOLD) {
    // Increase motor speed
    analogWrite(MOTOR_PIN_ENA, 100);    // Set the motor speed to a value (150)
    digitalWrite(MOTOR_PIN_IN1, HIGH);  // Set motor direction (forward)
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor Speed: Med");
  }
  else {
    // Decrease motor speed
    analogWrite(MOTOR_PIN_ENA, 45);    // Set the motor speed to a lower value (150)
    digitalWrite(MOTOR_PIN_IN1, HIGH);  // Set motor direction (forward)
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor Speed: Low");
  }

  lcd.setCursor(12, 0); // Set cursor to the temperature position on the first line
  lcd.print(temperature); // Print temperature
}
