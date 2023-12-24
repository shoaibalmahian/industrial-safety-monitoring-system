#define SENSOR_PIN A0
void setup() {
  // put your setup code here, to run once:
pinMode(SENSOR_PIN, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
long i= analogRead(SENSOR_PIN);

Serial.println(i);


delay(1000);
}
