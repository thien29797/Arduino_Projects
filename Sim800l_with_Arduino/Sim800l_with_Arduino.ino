#include <SoftwareSerial.h>

SoftwareSerial sim(10, 11); // TX -> 10; RX -> 11

String number = "+84969776490";

int led = 4;               
int sensor = 2;              
int state = LOW;             
int val = 0;   

void setup() {
  pinMode(led, OUTPUT); 
  pinMode(sensor, INPUT); 
  Serial.begin(9600);
  delay(500);
  sim.begin(9600);
//  SendMessage("Test");
//  delay(1000);
//  callNumber();
  
}

void loop() {
//    val = digitalRead(sensor);
//    
//      if (val == HIGH) {      
//        digitalWrite(led, HIGH);
//        delay(100);              
//        
//        if (state == LOW) {
////          Serial.println("Motion detected!");
////          String data = "Motion detected!";
////          SendMessage(data); 
//          callNumber();
//          state = HIGH;       
//        }
//      } 
//      else {
//          digitalWrite(led, LOW);
//          delay(200);             
//          
//          if (state == HIGH){
////            Serial.println("Motion stopped!");
////            String data = "Motion stopped!";
////            SendMessage(data);
//            state = LOW;       
//        }
//      }
//    
  delay(1000);
  SendMessage("test");
  Serial.println("SMS sended");
  delay(2000);
//  callNumber();
//  Serial.println("called");
//  delay(2000);
}

void SendMessage(String data)
{
  sim.println("AT+CMGF=1");
  delay(2000);
  sim.println("AT+CMGS=\"" + number + "\"\r");
  delay(2000);
  String SMS = data;
  sim.println(SMS);
  delay(1000);
  sim.println((char)26);
  delay(1000);
}

void callNumber() {
  sim.print (F("ATD"));
  sim.print (number);
  sim.print (F(";\r\n"));
}
/////////////////////////////////////////////////////////////////////////////////////
