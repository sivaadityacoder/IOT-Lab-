#include<LiquidCrystal.h>

int relay = 8;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);



void setup()
{
  lcd.begin(16, 2);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  project_Name();
}

void loop()
{
  int ldr_sensor_data = analogRead(A0);
  lcd.setCursor(0,0);
  lcd.print("LDR Data:       ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(9,0);
  lcd.print(ldr_sensor_data);
  if(ldr_sensor_data >100)
  digitalWrite(relay, HIGH);
  else
  digitalWrite(relay, LOW);
  delay(500);
}

void project_Name(){
  lcd.setCursor(0,0);
  lcd.print("LDR SENSOR       ");
  lcd.setCursor(0,1);
  lcd.print("INTERFACING      ");
  delay(3000);
  lcd.clear();
}
