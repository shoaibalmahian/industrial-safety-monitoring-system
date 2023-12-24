int gas ;
void setup()
{
  Serial.begin(9600);
  }
  void loop()
  {
    gas= digitalRead(2);
    Serial.println(gas);\
    delay(1000);
    
    }
