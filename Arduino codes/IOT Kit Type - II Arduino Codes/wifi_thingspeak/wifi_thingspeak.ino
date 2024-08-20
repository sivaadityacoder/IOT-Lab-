#include <dht.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
SoftwareSerial wifi(8, 9); // TX, RX

String apiKey = "L84GH3HBN8LTCQEZ";     ///  Write API Key

dht DHT;

#define DHT11_PIN 10



void setup(){
  lcd.begin(16, 2);
  project_Name();
  Serial.begin(9600);

  Serial.println("AT");
  delay(1000);
  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
  
  lcd.setCursor(0,0);
  lcd.print("WiFi module     ");
  lcd.setCursor(0,1);
  lcd.print("Initilizing.... ");
  wifi.begin(115200);
  wifi.println("AT+RST");
  delay(4000);
  wifi.println("AT+CWMODE=3");
  delay(4000);
  wifi.print("AT+CWJAP=");
  wifi.write('"');
  wifi.print("STTMANI");
  wifi.write('"');
  wifi.write(',');
  wifi.write('"');
  wifi.print("hailucky123,./");
  wifi.write('"');
  wifi.println();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("WiFi module     ");
  lcd.setCursor(0,1);
  lcd.print("Initilized..... ");
  delay(1000);
  lcd.clear();
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0);
  lcd.print("Temperature:    ");
  lcd.setCursor(0,1);
  lcd.print("Humidity:       ");
  lcd.setCursor(12,0);
  lcd.print(DHT.temperature);
  lcd.setCursor(9,1);
  lcd.print(DHT.humidity);
  delay(500);
  lcd.setCursor(15,1);
  lcd.write(0x20);
  SendWiFi_Data();
  delay(1000);
}

void SendWiFi_Data(){
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  wifi.println(cmd);
  delay(1500);

  String getStr ="GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(DHT.temperature);
  getStr +="&field2=";
  getStr += String(DHT.humidity);
  
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  wifi.println(cmd);
  delay(1500);
  wifi.println(getStr);
  delay(1000);
}


void project_Name(){
  lcd.setCursor(0,0);
  lcd.print("     ESP8266    ");
  lcd.setCursor(0,1);
  lcd.print("  Interfacing   ");
  delay(3000);
  lcd.clear();
}
