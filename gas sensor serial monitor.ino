int gas ;
void setup()
{
  Serial.begin(9600);
  }
  void loop()
  {
    gas= analogRead(A0);
    Serial.println(gas);\
    delay(1000);
    
    }
