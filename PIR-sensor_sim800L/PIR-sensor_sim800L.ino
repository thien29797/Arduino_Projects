//Bai 16

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
  delay(500);
  
}

void loop() {
    val = digitalRead(sensor);
    
      if (val == HIGH) {      
        digitalWrite(led, HIGH);
        delay(100);              
        
        if (state == LOW) {
          Serial.println("Motion detected!");
          String data = "Motion detected!";
          SendMessage(data); 
          delay(100);
          callNumber();
          state = HIGH;       
        }
      } 
      else {
          digitalWrite(led, LOW);
          delay(200);             
          
          if (state == HIGH){
            Serial.println("Motion stopped!");
            String data = "Motion stopped!";
            SendMessage(data);
            state = LOW;       
        }
      }
    
}

void SendMessage(String data)
{
  sim.println("AT+CMGF=1");
  delay(500);
  sim.println("AT+CMGS=\"" + number + "\"\r");
  delay(500);
  String SMS = data;
  sim.println(SMS);
  delay(100);
  sim.println((char)26);
  delay(1000);
}

void callNumber() {
  sim.print (F("ATD"));
  sim.print (number);
  sim.print (F(";\r\n"));
}
