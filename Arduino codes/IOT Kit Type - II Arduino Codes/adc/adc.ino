#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


void setup() {
  lcd.begin(16, 2);
  }

void loop() {
  int Varaible_resistor_data = analogRead(A0);
  lcd.setCursor(0,0);
  lcd.print("Resistance value");
  lcd.setCursor(0,1);
  lcd.print("           ");
  lcd.setCursor(0,1);
  lcd.print(Varaible_resistor_data);  
  delay(500);
}

void project_name()
{
  lcd.setCursor(0, 0);
  lcd.print("Analog input    "); 
  lcd.setCursor(0, 1);
  lcd.print("Digital Output  ");
  delay(5000);
  lcd.clear();
}
