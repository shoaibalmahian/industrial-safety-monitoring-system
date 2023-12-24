  int mq2 =2;
int gasbuzzer = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mq2,INPUT);
  pinMode(gasbuzzer,OUTPUT);

}

void loop() {
 
int gas=digitalRead(2);
Serial.println(gas);
if(gas==0)
{
  digitalWrite(gasbuzzer,HIGH);
  delay(1000);
  }
  else
  {
    
  digitalWrite(gasbuzzer,LOW);
    }
}
