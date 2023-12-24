  
   int ALCOHOL_sensor = 3;// MQ-6 SENSOR  
      int ALCOHOL_detected;  
      void setup()  
       {  
         Serial.begin(9600);  
         
         pinMode(ALCOHOL_sensor, INPUT);  
       }  
       void loop()  
       {  
         ALCOHOL_detected = digitalRead(ALCOHOL_sensor);  
          Serial.println(ALCOHOL_detected);  
        
       }  
