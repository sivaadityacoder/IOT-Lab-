const int led = 2;
const int input_switch = 3;

void setup() {
pinMode(led, OUTPUT);
pinMode(input_switch, INPUT_PULLUP);
}

void loop() {
if(digitalRead(input_switch) == LOW)
{
digitalWrite(led, HIGH);
delay(1000);
}
else
digitalWrite(led, LOW);
}
