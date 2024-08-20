#include <dht.h>

#define DHT11_PIN 10

dht DHT;

int incomingByte = 0;

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("TMP: ");
  Serial.println(DHT.temperature);
  delay(50);
  Serial.print("Hum: ");
  Serial.println(DHT.humidity);
  delay(2000);
}
