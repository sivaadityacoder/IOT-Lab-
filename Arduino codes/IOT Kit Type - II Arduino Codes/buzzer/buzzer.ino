const int buzzer = 2;

void setup() {
 pinMode(buzzer, OUTPUT);
 digitalWrite(buzzer, LOW);
}

void loop() {
digitalWrite(buzzer, HIGH);
delay(1000);
digitalWrite(buzzer, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
delay(1000);
digitalWrite(buzzer, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
delay(1000);
digitalWrite(buzzer, LOW);
delay(500);
while(1);
}
