// Define pin connections
const int gasSensorPin = 2;  // Digital pin connected to the gas sensor
const int fanPin = 3;        // Digital pin connected to the fan relay
const int buzzerPin = 4;     // Digital pin connected to the buzzer relay

void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the digital output from the gas sensor
  int gasValue = digitalRead(gasSensorPin);

  // Check if gas is detected (digital output is HIGH)
  if (gasValue == HIGH) {
    // Turn on the fan and buzzer
    digitalWrite(fanPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(2000);
  } else {
    // Turn off the fan and buzzer
    digitalWrite(fanPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  // Add a delay to avoid rapid switching
  delay(1000);
}
