int button = 11;
int led1 = 2;
int led2 = 3;
void setup() {
  pinMode(button, INPUT);  //Cài đặt chân D11 ở trạng thái đọc dữ liệu
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);// Cài đặt chân D2 dưới dạng OUTPUT
}

void loop() {
  int buttonStatus = digitalRead(button);    //Đọc trạng thái button
  if (buttonStatus == HIGH) { // Nếu mà button bị nhấn
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);// Đèn led sáng
  } else { // ngược lại
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  }
}
