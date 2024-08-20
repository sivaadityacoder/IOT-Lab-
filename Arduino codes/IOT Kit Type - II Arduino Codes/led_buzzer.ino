const int buzzer = 12;

void setup() {
 pinMode(buzzer, OUTPUT);
 digitalWrite(buzzer, LOW);
}

void loop() {
digitalWrite(buzzer, HIGH);
delay(1000);
digitalWrite(buzzer, LOW);
delay(2000);
}
