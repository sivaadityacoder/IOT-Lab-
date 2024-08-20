#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int trigPin = 12;
const int echoPin = 14;

long duration;
int distance;

void setup() {
lcd.begin(16, 2);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
project_name();
}

void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
lcd.setCursor(0, 0);
lcd.print("Distance:       ");
lcd.setCursor(9, 0);
lcd.print(distance);
lcd.setCursor(0, 1);
lcd.print("                ");
delay(600);
}

void project_name()
{
  lcd.setCursor(0, 0);
  lcd.print("ULTRASONIC SENSR");
  lcd.setCursor(0, 1);
  lcd.print("    HC-SR04     ");
  delay(2000);
  lcd.clear();
}
