#include <LEDmatrix.h>

LEDmatrix ::LEDmatrix(int datapin, int clockpin, int latchpin, int R1, int R2, int R3, int R4, int R5, int R6, int R7, int R8) : datapin (datapin), clockpin (clockpin),latchpin (latchpin),R1  (R1) ,R2  (R2) ,R3  (R3) ,R4  (R4) ,R5  (R5) ,R6  (R6) ,R7  (R7) ,R8  (R8) {}
 
LEDmatrix ::~LEDmatrix(){}
  
void LEDmatrix :: initialize(){
  pinMode(datapin,OUTPUT); 
  pinMode(clockpin,OUTPUT);
  pinMode(latchpin,OUTPUT);

  initializePinRow();

}


void LEDmatrix :: initializePinRow(){
    
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(R5,OUTPUT);
  pinMode(R6,OUTPUT);
  pinMode(R7,OUTPUT);
  pinMode(R8,OUTPUT);
}


void LEDmatrix ::rowOn(int n){
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

void LEDmatrix :: rowOff(int n){
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

void LEDmatrix :: AllRowOff(){
    digitalWrite(R1,HIGH);
    digitalWrite(R2,HIGH);
    digitalWrite(R3,HIGH);
    digitalWrite(R4,HIGH);
    digitalWrite(R5,HIGH);
    digitalWrite(R6,HIGH);
    digitalWrite(R7,HIGH);
    digitalWrite(R8,HIGH);
}


void LEDmatrix :: updateShiftRegister(byte leds){
  digitalWrite(latchpin,LOW);
  shiftOut(datapin,clockpin,MSBFIRST,leds);
  digitalWrite(latchpin,HIGH);
}


void LEDmatrix :: turnOnLED(int row, int column){
  int leds = 0; 
  for(int i=0 ;i<matrixLen; i++){
    AllRowOff();
    leds = power(2,i);
    updateShiftRegister(leds);
    if(i+1 == column){
      rowOn(row);
    }
    else{
      rowOff(row);
    }
    delay(tDelay);
  }
  rowOff(row);
}

void LEDmatrix :: turnOnLEDs(List positions){
  List positionsSameColumn;
  int row;
  int leds = 0; 
  for(int i=0 ;i<matrixLen; i++){
    AllRowOff();
    leds = power(2,i);
    updateShiftRegister(leds);
    positionsSameColumn = positions.SearchSameColumn(i+1);
    while(positionsSameColumn.getLength()!=0){
      row = (positionsSameColumn.First()).getRow();
      positionsSameColumn.DeleteFirst();
      rowOn(row);
    }
    
    delay(tDelay);
  }
  //rowOff(row);
}



void LEDmatrix::turnOnLEDsDelay(List positions, int delay){
  float time1 = millis();
  while(abs(time1-millis())<delay){
    turnOnLEDs(positions);
  }
}
