#include <dht.h>
#include<LiquidCrystal.h>

#define DHT11_PIN 10

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

dht DHT;


void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0);
  lcd.print("TMP:            ");
  lcd.setCursor(0,1);
  lcd.print("Hum:            ");
  lcd.setCursor(4,0);
  lcd.print(DHT.temperature);
  lcd.setCursor(4,1);
  lcd.print(DHT.humidity);
  delay(500);
  }
