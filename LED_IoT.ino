#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WebServer.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //inisialisasi lcd

WebServer server(80);

const char* ssid = "van";
const char* password = "nas1goreng";

const int ledDef = 2;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 18;
const int ledPin4 = 19;

bool LED1State = false;
bool LED2State = false;
bool LED3State = false;
bool LED4State = false;

void setup() {
  Serial.begin(115200);

  //inisialisasi lagi
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("WELCOME!");
  lcd.setCursor(0, 1);
  lcd.print("Conn to ");
  lcd.print(ssid);

  pinMode(ledDef, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wifi...");

  while(WiFi.status() != WL_CONNECTED){
    digitalWrite(ledDef, LOW);
    delay(1000);
    Serial.print(".");
  }
  digitalWrite(ledDef, HIGH);
  Serial.println("");
  Serial.print("Connected to SSID: ");
  Serial.println(ssid);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  //tampil di lcd king
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connected to ");
  lcd.print(ssid);
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());

  server.on("/satu", HTTP_GET, getLED1);
  server.on("/dua", HTTP_GET, getLED2);
  server.on("/tiga", HTTP_GET, getLED3);
  server.on("/empat", HTTP_GET, getLED4);

  server.on("/satu", HTTP_POST, setLED1);
  server.on("/dua", HTTP_POST, setLED2);
  server.on("/tiga", HTTP_POST, setLED3);
  server.on("/empat", HTTP_POST, setLED4);

  server.begin();
  Serial.println("Server started!");
}

void loop() {
  server.handleClient();
}

void setLED1(){
  LED1State = !LED1State;
  digitalWrite(ledPin1, LED1State ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", LED1State ? "ON" : "OFF");
}

void setLED2(){
  LED2State = !LED2State;
  digitalWrite(ledPin2, LED2State ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", LED2State ? "ON" : "OFF");
}

void setLED3(){
  LED3State = !LED3State;
  digitalWrite(ledPin3, LED3State ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", LED3State ? "ON" : "OFF");
}

void setLED4(){
  LED4State = !LED4State;
  digitalWrite(ledPin4, LED4State ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", LED4State ? "ON" : "OFF");
}

void getLED1(){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", LED1State ? "ON" : "OFF");
}

void getLED2(){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", LED2State ? "ON" : "OFF");
}

void getLED3(){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", LED3State ? "ON" : "OFF");
}

void getLED4(){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", LED4State ? "ON" : "OFF");
}