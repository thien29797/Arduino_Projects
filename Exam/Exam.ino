#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <MaxMatrix.h>
#include <DHT.h>
#include <TM1637Display.h>
#include <IRremote.h>

int relayPin = 2;
const int receiverPin = 3;
IRrecv irrecv(receiverPin);
decode_results results;

// SDA -> 10
// MOSI -> 11
// MISO -> 12
// SCK -> 13
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

Servo myservo;
int pos = 0;

LiquidCrystal_I2C lcd(0x27,16,2);
byte degree[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
};

//#define CLK_TM 2
//#define DIO 3
//int numCounterTM = 0;
//TM1637Display display(CLK_TM, DIO);

const int DHTPIN = 8;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);

int DIN = 7;   // DIN pin of MAX7219 module
int CLK_LED = 6;   // CLK pin of MAX7219 module
int CS = 5;    // CS pin of MAX7219 module
int maxInUse = 1;
MaxMatrix m(DIN, CS, CLK_LED, maxInUse);
char smile[] = {8, 8,
                  B00111100,
                  B01000010,
                  B10010101,
                  B10100001,
                  B10100001,
                  B10010101,
                  B01000010,
                  B00111100
                 };
char sad[] = {8, 8,
                  B00111100,
                  B01000010,
                  B10100101,
                  B10010001,
                  B10010001,
                  B10100101,
                  B01000010,
                  B00111100
                 };
 
void setup() 
{
  Serial.begin(9600);
  
  lcd.init();  
  lcd.backlight();    
  lcd.createChar(1, degree);
  
  myservo.attach(4);

  m.init(); // MAX7219 initialization
  m.setIntensity(5); // initial led matrix intensity, 0-15

//  display.setBrightness(0x0a);
  pinMode(relayPin, OUTPUT);
  //digitalWrite(relayPin, HIGH);

  irrecv.enableIRIn();

  //pinMode(buttonPin, INPUT);

  dht.begin(); 
  
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  float temp = dht.readTemperature();
//  int buttonStatus = digitalRead(buttonPin);
//  Serial.print("button status ");
//  Serial.println(buttonStatus);
  
  lcd.setCursor(7,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("Identity");  
  lcd.setCursor(7,2);
  lcd.print("        ");
  lcd.setCursor(0,1); 
  lcd.print("State: Close");
  lcd.setCursor(12, 1);  
  lcd.print("|");
  lcd.setCursor(13, 1);  
  lcd.print(round(temp));
  lcd.setCursor(15, 1);  
  lcd.print("C");

  matrixDisplay(temp);

  delay(1000);

  if (irrecv.decode(&results))
  {
    
    if (results.value == 16724175 || results.value == 2534850111) {
      digitalWrite(relayPin, LOW);
           
    }

    if (results.value == 16718055 || results.value == 4294967295 || results.value == 1033561079) {
      digitalWrite(relayPin, HIGH);
          
    }
  }
  Serial.println(results.value);
  irrecv.resume();
  delay(200);

//  remote();

//  if (buttonStatus == HIGH) {
//    digitalWrite(relayPin, HIGH);
//  } 
  
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  if (content.substring(1) == "01 02 03 04") {
    
    Serial.println("Authorized access");
    Serial.println();

    digitalWrite(relayPin, LOW);
    lcdDisplay(temp);    
    sweepServo();
    //tempDisplay(temp);
    
    
  
    delay(500);
  }
 
 else   {
    Serial.println(" Access denied");
    lcd.setCursor(0,0);
    lcd.print("                   ");
    lcd.setCursor(0,0);
    lcd.print("Access denied");
    delay(500);
  }
  delay(3000);
} 

void lcdDisplay(float temp) {
  lcd.setCursor(0,0);
  lcd.print("                 ");
  lcd.setCursor(7,1);
  lcd.print("            ");
  lcd.setCursor(0,0);
  lcd.print("Hello Thien");
  lcd.setCursor(8,1);
  lcd.print("Open");
  lcd.setCursor(12, 1);  
  lcd.print("|");
  lcd.setCursor(13, 1);  
  lcd.print(round(temp));
  lcd.setCursor(15, 1);  
  lcd.print("C");
}

void sweepServo() {  
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
  delay(2000);
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);              
    delay(15);                       
  }
  
}

//void tempDisplay(float temp) {
//  numCounterTM = round(temp);
//  display.showNumberDec(numCounterTM, true, 2, 1);  
//  delay(500);
//}

void matrixDisplay(float temp) {
  if (temp <= 32) {
    m.writeSprite(0, 0, smile);
  }
  else {
    m.writeSprite(0, 0, sad);
  }
}

void remote() {
  
  if (irrecv.decode(&results))
  {
    
    if (results.value == 16724175 || results.value == 2534850111) {
      digitalWrite(relayPin, LOW);
           
    }

    if (results.value == 16718055 || results.value == 4294967295) {
      digitalWrite(relayPin, HIGH);
          
    }
  }
  Serial.println(results.value);
  irrecv.resume();
  delay(200);
}
