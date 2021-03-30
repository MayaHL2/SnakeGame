#ifndef LEDmatrix_hpp
#define LEDmatrix_hpp

#include<Arduino.h>
#include "Mathematics.h"

#define datapin 12
#define clockpin 9
#define latchpin 11 

#define matrixLen 5 // size of the LEDmatrix
#define tDelay 1000  // delay of the leds' flashing

#define R1 3
#define R2 4
#define R3 5
#define R4 6
#define R5 7
#define R6 11
#define R7 12
#define R8 13

void initializePinRow(); // initialization of all the pins in a row
void initializePin(); // initialization of the pins connected to the shift register
void rowOn(int n); // put row n HIGH
void updateShiftRegister(byte leds); // put value of the columns as HIGH depending on the value of leds (e.g leds = 1000 => column 1 on the rest off)
void turnOnLED(int row, int column); // turn on only one led on the LEDmatrix  

#endif