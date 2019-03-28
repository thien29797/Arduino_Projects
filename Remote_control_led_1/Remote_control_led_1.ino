// 10-12-16
// IN -> 8
// COM -> 7
// IR Receiver: IN -> 3
// NO -> Lamp
// COM -> +AC

#include <IRremote.h>
#include <SoftwareSerial.h>

SoftwareSerial sim(10, 11); // TX -> 10; RX -> 11

String number = "+84969776490";

const int receiverPin = 3;
const int relay_pin = 8;
int state = 1;
String data;
//const  int led_pin = 7;
IRrecv irrecv(receiverPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  irrecv.enableIRIn();
  pinMode(relay_pin,OUTPUT);
//  pinMode(led_pin,OUTPUT);  
  sim.begin(9600);
//  digitalWrite(led_pin,HIGH);
}

void loop() {
  if (irrecv.decode(&results))
  {
    
    if (results.value == 16724175) {
      digitalWrite(relay_pin, LOW);
      state = 1;
      //delay(2000);      
    }

    if (results.value == 16718055) {
      digitalWrite(relay_pin, HIGH);
      state = 0;
      //delay(2000);      
    }

    if (results.value == 16743045) {
      callNumber();            
    }

    if (results.value == 16716015) {
      if(state == 1) {
        data = "Lamp has been turned on";
        sendMessage(data);
      }
      else {
        data = "Lamp has been turned off";
        sendMessage(data);
      }
    }
    Serial.println(results.value);
  }
  
  irrecv.resume();
  delay(200);
}

void sendMessage(String data)
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
