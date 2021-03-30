#include <Arduino.h>
#include <List.h>
#include <LEDmatrix.h>
#include <Mathematics.h>

int leds=0;

List pos;

void setup() {
  Serial.begin(115200);

  pinMode(12,INPUT);

  pos.Append(2);
  pos.Append(3);
  pos.Append(7);

  Serial.println(pos.getLength());

  initializePin();

}
  
void loop() {
  turnOnLED(2,3);

}