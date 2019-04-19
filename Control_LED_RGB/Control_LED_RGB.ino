//Bai 14

int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int soundSensor = 2;
int soundSensorAnalog = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(soundSensor, INPUT);
  pinMode(soundSensorAnalog, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for (int i = 0; i <= 255; i++) {
//    for (int j = 255; j > 0; j--) {
//      for (int k = 0; k <=255; j++) {
//        setColor(i, j, k);
//        delay(100);
//      }
//    }
//  }

  int analogValue = analogRead(soundSensorAnalog);
  int soundValue = digitalRead(soundSensor);
  if(soundValue == 1) {
    setColor(analogValue, analogValue, analogValue);  
  }
  
//  setColor(random(255),random(255),random(255));
  Serial.println(analogValue);  
  delay(100);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue); 
}
