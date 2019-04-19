//Bai 6-7

#include <Keypad.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);
 
const byte rows = 4;
const byte columns = 4;
 
int holdDelay = 700;
int n = 3; 
int state = 0;
char key = 0;
int numCounter = 0;
 
char keys[rows][columns] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
 
byte rowPins[rows] = {5, 6, 7, 8};
byte columnPins[columns] = {9, 10, 11, 12};
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);

void setup() {
  Serial.begin(9600);
  display.setBrightness(0x0a);
}

void loop() {  
  char temp = keypad.getKey();
 
  if ((int)keypad.getState() ==  PRESSED) {
    if (temp != 0) {
      key = temp;
    }
  }
  if ((int)keypad.getState() ==  HOLD) {
    state++;
    state = constrain(state, 1, n-1);
    delay(holdDelay);
  }
 
  if ((int)keypad.getState() ==  RELEASED) {
    key += state;
    state = 0;
    Serial.println(key);

  switch(key) {

    case '1':
      numCounter = 1;
      break;
    case '2':
      numCounter = 2;
      break;
    case '3':
      numCounter = 3;
      break;
    case '4':
      numCounter = 4;
      break;
    case '5':
      numCounter = 5;
      break;
    case '6':
      numCounter = 6;
      break;
    case '7':
      numCounter = 7;
      break;
    case '8':
      numCounter = 8;
      break;
    case '9':
      numCounter = 9;
      break;
    case '0':
      numCounter = 0;
      break;
    case 'A':
      numCounter++;
      break;
    case 'B':
      numCounter--;
      break;
    case 'C':
      while (numCounter < 100) {
        numCounter++;
        delay(100);
        display.showNumberDec(numCounter);
      }
      break;
    case 'D':
      while (numCounter != 0) {
        numCounter--;
        delay(100);
        display.showNumberDec(numCounter);
      }
      break;
  }  
  }

  display.showNumberDec(numCounter);
  
  delay(400);
}
