#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
 
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
 
void setup() 
{
  Serial.begin(9600);
  lcd.init();  
  lcd.backlight();    
  lcd.createChar(1, degree);
  myservo.attach(4);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  lcd.setCursor(7,0);
  lcd.print("        ");
  lcd.setCursor(0,0);
  lcd.print("Hello ");  
  lcd.setCursor(7,2);
  lcd.print("        ");
  lcd.setCursor(0,1); 
  lcd.print("State: Close");  
  
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
    
    lcd.setCursor(7,1);
    lcd.print("         ");
    lcd.setCursor(7,0);
    lcd.print("Thien");
    lcd.setCursor(8,1);
    lcd.print("Open");
    sweepServo();
  
    delay(500);
  }
 
 else   {
    Serial.println(" Access denied");
    delay(500);
  }
  delay(1000);
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
