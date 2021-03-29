#ifndef LEDmatrix_hpp
#define LEDmatrix_hpp

#include<Arduino.h>

#define datapin 12
#define clockpin 9
#define latchpin 11 

#define R1 3
#define R2 4
#define R3 5
#define R4 6
#define R5 7
#define R6 11
#define R7 12
#define R8 13

void initializePinRow();
void initializePin();
void row(int n);
void updateShiftRegister(byte leds);
void turnOnLED(int pos[]);

#endif