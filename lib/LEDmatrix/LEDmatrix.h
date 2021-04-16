#ifndef LEDmatrix_hpp
#define LEDmatrix_hpp

#include<Arduino.h>
#include <Mathematics.h>
#include <List.h>

#define matrixLen 5 // size of the LEDmatrix
#define tDelay 1 // delay of the leds' flashing

class LEDmatrix
{
private:

    int datapin;
    int clockpin;
    int latchpin; 
    int R1;
    int R2;
    int R3;
    int R4;
    int R5;
    int R6;
    int R7;
    int R8;

public:
    LEDmatrix(int datapin, int clockpin, int latchpin, int R1, int R2, int R3, int R4, int R5, int R6, int R7, int R8);
    ~LEDmatrix();
    void initializePinRow(); // initialization of all the pins in a row
    void initialize(); // initialization of the pins connected to the shift register
    void rowOn(int n); // put row n to GND
    void rowOff(int n); // put row n to VCC 
    void AllRowOff(); // put all rows to VCC
    void updateShiftRegister(byte leds); // put value of the columns as HIGH depending on the value of leds (e.g leds = 1000 => column 1 on the rest off)
    void turnOnLED(int row, int column); // turn on only one led on the LEDmatrix  
    void turnOnLEDs(List positions); //turn on leds on the LEDmatrix depending on the positions given
};


#endif