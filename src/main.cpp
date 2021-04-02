#include <Arduino.h>
#include <List.h>
#include <LEDmatrix.h>
#include <Mathematics.h>

int leds=0;

#define datapin  12
#define clockpin  9
#define latchpin  11
#define R1  3
#define R2  4
#define R3  5
#define R4  6
#define R5  7
#define R6  8
#define R7  10
#define R8  13



LEDmatrix matrix(datapin, clockpin, latchpin, R1, R2, R3, R4, R5, R6, R7, R8);

List positions;
Position pos1(1,2);
Position pos2(3,4);

void setup() {
  Serial.begin(115200);
  
  matrix.initialize();


}
  
void loop() {
  matrix.turnOnLED(1,2);
  matrix.turnOnLED(2,2);
  matrix.turnOnLED(5,5);
}