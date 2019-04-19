// Bai 10-12
// IN -> 8
// COM -> 7
// IR Receiver: IN -> 3
// NO -> Lamp
// COM -> +AC

#include <IRremote.h>

const int receiverPin = 3;
const int relay_pin = 8;

IRrecv irrecv(receiverPin);
decode_results results;

void setup() {
  Serial.begin(9600); 
  irrecv.enableIRIn();
  pinMode(relay_pin,OUTPUT);
}

void loop() {

  if (irrecv.decode(&results))
  {
    
    if (results.value == 16724175) {
      digitalWrite(relay_pin, LOW);      
    }

    if (results.value == 16718055) {
      digitalWrite(relay_pin, HIGH);     
    }
 }
  
  irrecv.resume();
  delay(200);
}
