#include <LiquidCrystal_I2C.h>
#include <TimeLib.h>

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

char blueToothVal;           //value sent over via bluetooth
char lastValue;
String noti;//stores last state of device (on/off)
 
void setup()
{
 Serial.begin(9600); 
 pinMode(13,OUTPUT);
 lcd.init();  
 lcd.backlight();    
 lcd.createChar(1, degree);
} 
 
void loop()
{
  if (Serial.available())
  {//if there is data being recieved
    blueToothVal=Serial.read(); //read it
  }
  if (blueToothVal=='a')
  {//if value from bluetooth serial is n
    digitalWrite(13,LOW);            //switch on LED
    if (lastValue!='a')
      noti = "Lamp is on"; //print LED is on
      printLCD(noti);
      lastValue=blueToothVal;
  }
  else if (blueToothVal=='b')
  {//if value from bluetooth serial is n
    digitalWrite(13,HIGH);             //turn off LED
    if (lastValue!='b')
      noti = "Lamp is off"; //print LED is on
      printLCD(noti);
      lastValue=blueToothVal;
  }
  delay(1000);
}

void printLCD(String notifi) {
  lcd.setCursor(0,0);
  lcd.print(notifi);
  delay(50);
//  lcd.setCursor(0,1); 
//  lcd.print("Time: ");
  
}
