

#include <Servo.h>
//Bai 11

const int trig = 8;
const int echo = 9;
Servo myservo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  myservo.attach(10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(1000);
  unsigned long duration;
  int distanceCm;
    
  
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(5);
  digitalWrite(trig,0);
    
  
  duration = pulseIn(echo,HIGH);  
 
  distanceCm = int(duration/2/29.412);
 
  Serial.println(distanceCm);
  if (distanceCm < 200) {
    runDoor();
  }
}

void runDoor() {
  for ( pos = 0; pos <= 90; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  Serial.println("The door was opened");
  delay(4000);
  for ( pos = 90; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  Serial.println("The door was closed");
}
