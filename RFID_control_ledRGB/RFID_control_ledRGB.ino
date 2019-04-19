//Bai 15

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
 
#define SS_PIN 10
#define RST_PIN 9
String content= "";
const int RED_PIN = 2;
const int GREEN_PIN = 3;
const int BLUE_PIN = 4;

MFRC522 mfrc522(SS_PIN, RST_PIN);

int DELAY_TIME = 500;

void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println();

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
}
void loop() 
{
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //Serial.println(frc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();Serial.println(content);
  if (content.substring(1) == "51 B6 EA A9") 
  {
    content="";
    displayAllBasicColors(content);

    showSpectrum();

    }
    else {
      Serial.println("Access denied");
    }
    delay(1000);

} 

int recieveData(String content){
  if (content.substring(1) == "51 B6 EA A9")
    return 0;
  else 1;
}



void displayAllBasicColors(String content)
{
  
 
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  
  delay(DELAY_TIME);

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
 
  delay(DELAY_TIME);
    
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
 
  delay(DELAY_TIME);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(DELAY_TIME);

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
 
  delay(DELAY_TIME);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(DELAY_TIME);

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(DELAY_TIME);

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(DELAY_TIME);

}

 

 
 
void showSpectrum()
{
  
  for (int i = 0; i < 768; i++)
  {
    showRGB(i);  
    delay(10);  
  }
}

 
void showRGB(int color)
{
  int redPWM;
  int greenPWM;
  int bluePWM;
 
 
 
  if (color <= 255)         
  {
    redPWM = 255 - color;   
    greenPWM = color;        
    bluePWM = 0;             
  }
  else if (color <= 511)   
  {
    redPWM = 0;                     
    greenPWM = 255 - (color - 256);
    bluePWM = (color - 256);       
  }
  else 
  {
    redPWM = (color - 512);        
    greenPWM = 0;                   
    bluePWM = 255 - (color - 512);  
  }
 
 
  analogWrite(RED_PIN, redPWM);
  analogWrite(BLUE_PIN, bluePWM);
  analogWrite(GREEN_PIN, greenPWM);
}
