//Bai 2-3-5

#include <DHT.h>
int led1=2;
int led2=3;
int led3=4;
int button1=7;
int state1=0;
int state2=0;
int button2=8;
int dhtpin=12;
int val1=0;
int val2=0;
int dhttype=DHT11;
DHT dht = DHT(dhtpin, dhttype);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  dht.begin();
}

void controlDHT(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Nhiet do: ");
  Serial.println(t);
  Serial.print("Do am: ");
  Serial.println(h);
  delay(1000);
}

void controlLed(int l1, int l2, int l3){
  digitalWrite(l1,HIGH);
  delay(500);
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  delay(500);
  digitalWrite(l2,LOW);
  digitalWrite(l3,HIGH);
  delay(500);
  digitalWrite(l3,LOW);
  delay(1000);
}

void Bai1(){
  controlLed(led1,led2,led3);
  controlLed(led3,led2,led1);
  controlLed(led2,led1,led3);
  controlLed(led2,led3,led1);
}

void loop() {
  // put your main code here, to run repeatedly:
  val1=digitalRead(button1);
  val2=digitalRead(button2);
  delay(2000);
  if(val1 == 1)
    state1 = 1-state1;
  if(state1 == 1)
    controlDHT();    
  if(val2 == 1)
    state2 = 1-state2;
  if(state2 == 1)
    Bai1();
}
