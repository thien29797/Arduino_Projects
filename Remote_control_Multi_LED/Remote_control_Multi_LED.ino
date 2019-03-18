#include <IRremote.h>

int receiverPin = 7;
int butt1 = 8;
int butt2 = 9;
int led1 = 2;
int led2 = 3;
int led3 = 4;

IRrecv irrecv(receiverPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(butt1, INPUT);
  pinMode(butt2, INPUT);
}

void loop() {

  int butt1Status = digitalRead(butt1);
  int butt2Status = digitalRead(butt2);
  
  if (irrecv.decode(&results))
  {
    
    if (results.value == 16724175) {
      digitalWrite(led1, HIGH);            
    }

    if (results.value == 16718055) {
      digitalWrite(led2, HIGH);   
    }

    if (results.value == 16743045) {
      digitalWrite(led3, HIGH);            
    }

    if (results.value == 16716015) {
      digitalWrite(led1, LOW);           
    }

    if (results.value == 16726215) {
      digitalWrite(led2, LOW);           
    }

    if (results.value == 16734885) {
      digitalWrite(led3, LOW);            
    }

    if (results.value == 16728765) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);            
    }

    if (results.value == 16730805) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);           
    }
    
    irrecv.resume();
  }

  if (butt1Status == HIGH) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } 
  else if (butt2Status == HIGH) {    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  
  delay(200);
}
