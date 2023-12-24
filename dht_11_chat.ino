#include <DHT.h>

#define DHTPIN 2  // Pin where the DHT11 is connected
#define DHTTYPE DHT11  // Type of the DHT sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Delay for 2 seconds between readings

  float temperature = dht.readTemperature();  // Read temperature in Celsius
  float humidity = dht.readHumidity();  // Read humidity

  // Check if the readings are valid
  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("Failed to read from DHT sensor");
  }
}
