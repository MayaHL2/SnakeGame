#include <Arduino.h>
#include <LinkedList.h>
#include <LEDmatrix.h>
#include <mathematics.h>

#define matrixLen 5
 
LinkedList <int> pos(); 


int tDelay=1000;
int leds=0;


void setup() {
  Serial.begin(115200);

  initializePin();

  digitalWrite(R1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(R3,LOW);
  digitalWrite(R4,LOW);
  digitalWrite(R5,LOW);

}
  
void loop() {

  leds=0;
  for(int i=0 ;i<matrixLen; i++){
    leds = power(2,i);

    Serial.println(leds);

    updateShiftRegister(leds);
    delay(tDelay);
  }  
}

