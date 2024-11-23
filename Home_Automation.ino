#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2,3);
#define light 4
#define fan 7

int bt_data;
               
void setup() 
{
   Serial.begin(9600);
   BT_Serial.begin(9600);
    
   pinMode(light, OUTPUT);
   digitalWrite(light, LOW);
   
   pinMode(fan, OUTPUT);
   digitalWrite(fan,LOW);
}
 
void loop() 
{
    
   if( BT_Serial.available()>0){
   bt_data= BT_Serial.read();
   Serial.println(bt_data);}  
         
    if(bt_data ==1)
    {
      digitalWrite(light,HIGH);
      Serial.println("lights on");
    }
    else if(bt_data == 2)
    {
      digitalWrite(light,LOW);
      Serial.println("lights off");
    }
    else if(bt_data== 3)
    {
      digitalWrite(fan,HIGH);
      Serial.println("fan on");
    }
    else if(bt_data== 4)
    {
      digitalWrite(fan,LOW);
      Serial.println("fan off");
    }
    else if(bt_data== 5)
    {
      digitalWrite(light,HIGH);
      digitalWrite(fan,HIGH);
      Serial.println("all on");
    }
    else if(bt_data == 6)
    {
      digitalWrite(light,LOW);
      digitalWrite(fan,LOW);
      Serial.println("all off");
     
    }
     
}
