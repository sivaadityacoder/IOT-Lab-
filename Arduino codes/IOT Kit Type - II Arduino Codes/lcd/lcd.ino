#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3, 4, 5, 6, 7);


void setup() {
  lcd.begin(16, 2);
  }

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("   16X2 LCD     ");
  lcd.setCursor(0, 1);
  lcd.print(" U R NAME HERE  ");
  delay(5000);
  lcd.clear();
}
