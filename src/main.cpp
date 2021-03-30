#include <Arduino.h>
#include <List.h>
#include <LEDmatrix.h>
#include <Mathematics.h>

int leds=0;

List pos;
Position pos1(1,2);
Position pos2(3,1);
Position pos3(2,5);

void setup() {
  Serial.begin(115200);

  pinMode(12,INPUT);

  initializePin();

  pos.Append(pos1);
  pos.Append(pos2);
  pos.Append(pos3);

  Serial.println(pos.getLength());

  Serial.println(pos1.inMatrix(5));
  Serial.println(pos1.inMatrix(1));

}
  
void loop() {
  turnOnLED(2,3);

}