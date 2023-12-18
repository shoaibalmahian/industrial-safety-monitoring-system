int pir=7;
int state;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pir,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  state=digitalRead(pir);
  Serial.println(pir);
  delay(1000);
  

}
