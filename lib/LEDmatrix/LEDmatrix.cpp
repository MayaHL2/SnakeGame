#include "LEDmatrix.h"
 
void initializePin(){
  pinMode(datapin,OUTPUT);
  pinMode(clockpin,OUTPUT);
  pinMode(latchpin,OUTPUT);

  initializePinRow();

}


void initializePinRow(){
    
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(R5,OUTPUT);
  pinMode(R6,OUTPUT);
  pinMode(R7,OUTPUT);
  pinMode(R8,OUTPUT);
}


void row(int n){
  switch (n)
  {
  case 1:
    digitalWrite(R1,LOW);
    break;
  
  case 2:
    digitalWrite(R2,LOW);
    break;

  case 3:
    digitalWrite(R3,LOW);
    break;

  case 4:
    digitalWrite(R4,LOW);
    break;
  
  case 5:
    digitalWrite(R5,LOW);
    break;
  
  case 6:
    digitalWrite(R6,LOW);
    break;
  
  case 7:
    digitalWrite(R7,LOW);
    break;

  case 8:
    digitalWrite(R8,LOW);
    break;

  default:
    break;
  }
}


void updateShiftRegister(byte leds){
  digitalWrite(latchpin,LOW);
  shiftOut(datapin,clockpin,MSBFIRST,leds);
  digitalWrite(latchpin,HIGH);
}


void turnOnLED(int pos[]){
  for (int i = 0; i < 2; i++)
  {
    row(pos[i]);
  }
  
}