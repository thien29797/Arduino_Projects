int led1 = 2;
int led2 = 3;
int led3 = 2;
int led4 = 3;
int led5 = 4;
int led6 = 5;
int led7 = 6;
int led8 = 7;
int led9 = 8;
int led10 = 9;
int led11 = 10;
int led12 = 11;
int led13 = 12;
int led14 = 8;
int led15 = 9;
int led16 = 10;
int led17 = 11;
int led18 = 12;
int soundSensor = 13;
int soundSensorAnalog = A5;
//int threshold = 550;
 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(led14, OUTPUT);
  pinMode(led15, OUTPUT);
  pinMode(led16, OUTPUT);
  pinMode(led17, OUTPUT);
  pinMode(led18, OUTPUT);
  pinMode(soundSensor, INPUT);
  pinMode(soundSensorAnalog, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //int soundSensorValue = analogRead(soundSensorAnalog);
  //Serial.println(soundSensorValue);
  
  int analogValue = analogRead(soundSensorAnalog);
  int soundValue = digitalRead(soundSensor);

  Serial.println(analogValue);
  
  if (soundValue == 1) {
    if (analogValue >= 500 && analogValue <= 520) {
      analogWrite(led1, 255);
      analogWrite(led2, 255);
      analogWrite(led3, 255);
      analogWrite(led4, 255);
//      analogWrite(led5, 255);
//      analogWrite(led6, 255);
//      analogWrite(led7, 255);
//      analogWrite(led8, 255);
//      analogWrite(led9, 255);
//      analogWrite(led10, 255);
//      analogWrite(led11, 255);
//      analogWrite(led12, 255);
//      analogWrite(led13, 255);
    } else if (analogValue > 520 && analogValue < 540) {
      analogWrite(led1, 255);
      analogWrite(led2, 255);
      analogWrite(led3, 255);
      analogWrite(led4, 255);
      analogWrite(led5, 255);
      analogWrite(led6, 255);
//      analogWrite(led7, 255);
//      analogWrite(led8, 255);
//      analogWrite(led9, 255);
//      analogWrite(led10, 255);
//      analogWrite(led11, 255);
//      analogWrite(led12, 255);
//      analogWrite(led13, 255);
    } else if (analogValue > 540 && analogValue < 560) {
      analogWrite(led1, 255);
      analogWrite(led2, 255);
      analogWrite(led3, 255);
      analogWrite(led4, 255);
      analogWrite(led5, 255);
      analogWrite(led6, 255);
      analogWrite(led7, 255);
      analogWrite(led8, 255);
//      analogWrite(led9, 255);
//      analogWrite(led10, 255);
//      analogWrite(led11, 255);
//      analogWrite(led12, 255);
//      analogWrite(led13, 255);
    } else if (analogValue > 560 && analogValue < 580) {
      analogWrite(led1, 255);
      analogWrite(led2, 255);
      analogWrite(led3, 255);
      analogWrite(led4, 255);
      analogWrite(led5, 255);
      analogWrite(led6, 255);
      analogWrite(led7, 255);
      analogWrite(led8, 255);
      analogWrite(led9, 255);
      analogWrite(led10, 255);
//      analogWrite(led11, 255);
//      analogWrite(led12, 255);
//      analogWrite(led13, 255);
    } else if (analogValue > 580 && analogValue < 600) {
      analogWrite(led1, 255);
      analogWrite(led2, 255);
      analogWrite(led3, 255);
      analogWrite(led4, 255);
      analogWrite(led5, 255);
      analogWrite(led6, 255);
      analogWrite(led7, 255);
      analogWrite(led8, 255);
      analogWrite(led9, 255);
      analogWrite(led10, 255);
      analogWrite(led11, 255);
      analogWrite(led12, 255);
      analogWrite(led13, 255);
    } else if (analogValue > 600 && analogValue < 620) {
      analogWrite(led1, 255);
      analogWrite(led2, 255);
      analogWrite(led3, 255);
      analogWrite(led4, 255);
      analogWrite(led5, 255);
      analogWrite(led6, 255);
      analogWrite(led7, 255);
      analogWrite(led8, 255);
      analogWrite(led9, 255);
      analogWrite(led10, 255);
      analogWrite(led11, 255);
      analogWrite(led12, 255);
      analogWrite(led13, 255);
      analogWrite(led14, 255);
      analogWrite(led15, 255);
      analogWrite(led16, 255);
    } else {
      analogWrite(led1, 255);
      analogWrite(led2, 255);
      analogWrite(led3, 255);
      analogWrite(led4, 255);
      analogWrite(led5, 255);
      analogWrite(led6, 255);
      analogWrite(led7, 255);
      analogWrite(led8, 255);
      analogWrite(led9, 255);
      analogWrite(led10, 255);
      analogWrite(led11, 255);
      analogWrite(led12, 255);
      analogWrite(led13, 255);
      analogWrite(led14, 255);
      analogWrite(led15, 255);
      analogWrite(led16, 255);
      analogWrite(led17, 255);
      analogWrite(led18, 255);
    }
//    digitalWrite(led1, HIGH);
//    digitalWrite(led2, HIGH);
//    digitalWrite(led3, HIGH);
//    digitalWrite(led4, HIGH);
//    digitalWrite(led5, HIGH);
//    digitalWrite(led6, HIGH);
//    digitalWrite(led7, HIGH);
  }
  else {
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    analogWrite(led5, 0);
    analogWrite(led6, 0);
    analogWrite(led7, 0);
    analogWrite(led8, 0);
    analogWrite(led9, 0);
    analogWrite(led10, 0);
    analogWrite(led11, 0);
    analogWrite(led12, 0);
    analogWrite(led13, 0);
    analogWrite(led14, 0);
    analogWrite(led15, 0);
    analogWrite(led16, 0);
    analogWrite(led17, 0);
    analogWrite(led18, 0);
//    digitalWrite(led1, LOW);
//    digitalWrite(led2, LOW);
//    digitalWrite(led3, LOW);
//    digitalWrite(led4, LOW);
//    digitalWrite(led5, LOW);
//    digitalWrite(led6, LOW);
//    digitalWrite(led7, LOW);
  }
}
