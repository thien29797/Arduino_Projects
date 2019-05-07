#include <SoftwareSerial.h>

String number = "+84969776490";

SoftwareSerial sim(10, 11); // TX -> 10; RX -> 11

const int buzzer = 8;
const int sensor = 2;
const int sensor1 = 4;
int state1;
int state;
int smsState = 1;
int smsState1 = 1;
int smsState2 = 1;

void setup(){
  Serial.begin (9600);
  pinMode (sensor, INPUT_PULLUP);
  pinMode (sensor1, INPUT_PULLUP);
  delay(500);
  sim.begin(9600);
  delay(500);
}

void loop() {

    state1 = digitalRead(sensor1);
    if (state1 == LOW) {
      if (smsState == 1) {
        Serial.println("Cua khoa");
        String data = "Cua khoa";
        SendMessage(data);
        smsState = 0;
        smsState1 = 1;
        smsState2 = 1;
        Serial.print("smsState: ");
        Serial.println(smsState);
        Serial.print("smsState1: ");
        Serial.println(smsState1);
        Serial.print("smsState2: ");
        Serial.println(smsState2);
        delay(200); 
        }
      }
     else {
        Cua();
     }
  delay (200);
}
void Cua() { 
  state = digitalRead(sensor);
    if (state == HIGH)
    {
      if (smsState1 == 1) {
        tone(buzzer,1000);
        Serial.println("Cua mo");
        String data = "Cua mo";
        SendMessage(data);
        smsState = 1;
        smsState1 = 0;
        smsState2 = 1;
        Serial.print("smsState: ");
        Serial.println(smsState);
        Serial.print("smsState1: ");
        Serial.println(smsState1);
        Serial.print("smsState2: ");
        Serial.println(smsState2);
        delay(200);
      }
     }
     else {
        if (smsState2 == 1) {
          noTone(buzzer);
          Serial.println("Cua dong");
          String data = "Cua dong";
          SendMessage(data);
          smsState = 1;
          smsState1 = 1;
          smsState2 = 0;
          Serial.print("smsState: ");
          Serial.println(smsState);
          Serial.print("smsState1: ");
          Serial.println(smsState1);
          Serial.print("smsState2: ");
          Serial.println(smsState2);
          delay(200);
         }
      }
    delay(200);
}
void SendMessage(String data) {
  sim.println("AT+CMGF=1");
  delay(500);
  sim.println("AT+CMGS=\"" + number + "\"\r");
  delay(500);
  String SMS = data;
  sim.println(SMS);
  delay(500);
  sim.println((char)26);
  Serial.println("Sended");
  delay(2000);
}

void callNumber() {
  sim.print (F("ATD"));
  sim.print (number);
  sim.print (F(";\r\n"));
}
