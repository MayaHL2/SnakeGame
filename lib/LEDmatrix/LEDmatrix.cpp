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


void rowOn(int n){
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

void rowOff(int n){
  switch (n)
  {
  case 1:
    digitalWrite(R1,HIGH);
    break;
  
  case 2:
    digitalWrite(R2,HIGH);
    break;

  case 3:
    digitalWrite(R3,HIGH);
    break;

  case 4:
    digitalWrite(R4,HIGH);
    break;
  
  case 5:
    digitalWrite(R5,HIGH);
    break;
  
  case 6:
    digitalWrite(R6,HIGH);
    break;
  
  case 7:
    digitalWrite(R7,HIGH);
    break;

  case 8:
    digitalWrite(R8,HIGH);
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


void turnOnLED(int row, int column){
  int leds = 0; 
  for(int i=0 ;i<matrixLen; i++){
    leds = power(2,i);
    if(i == column){
      rowOn(row);
    }
    else{
      rowOff(row);
    }
    updateShiftRegister(leds);
    delay(tDelay);
  }
}