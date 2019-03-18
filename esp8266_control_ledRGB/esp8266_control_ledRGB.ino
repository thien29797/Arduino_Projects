#include <ESP8266WiFi.h>

const char* ssid = "CPH1801";
const char* password = "tamhung123";

int ledB = D0;
int ledG = D1;
int ledR = D2;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare GPIOs for RGB LED
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  analogWriteRange(99); //PWM: 0~99
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  int valR, valG, valB;
  String subStringR, subStringG, subStringB;
  int index = req.indexOf("/rgb/");
  if(index != -1){
    if(req.charAt(index+11)=='/'){
      subStringR = req.substring(index+5, index+7);
      subStringG = req.substring(index+7, index+9);
      subStringB = req.substring(index+9, index+11);
      Serial.println("R: " + subStringR);
      Serial.println("G: " + subStringG);
      Serial.println("B: " + subStringB);

      valR = subStringR.toInt();
      valG = subStringG.toInt();
      valB = subStringB.toInt();
      Serial.println("valR: " + String(valR));
      Serial.println("valG: " + String(valG));
      Serial.println("valB: " + String(valB));
      
    }
    else{
      Serial.println("Not terminated with /");
      client.stop();
      return;
    }
  }
  else {
    Serial.println("No /rgb/ found");
    client.stop();
    return;
  }

  // Set GPIOs according to the request
  // No check valid of the requested setting
  analogWrite(ledR, valR);
  analogWrite(ledG, valG);
  analogWrite(ledB, valB);
  
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIOs of RGB is now ";
  s += String(valR) +":" + String(valG) + ":" + String(valB);
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}
