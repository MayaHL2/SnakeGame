#include <Arduino.h>
#include <List.h>
#include <LEDmatrix.h>
#include <Mathematics.h>
#include <SnakeGame.h>

int leds=0;

#define datapin  12
#define clockpin  9
#define latchpin  11
#define R1  3
#define R2  4
#define R3  5
#define R4  6
#define R5  7
#define R6  A0
#define R7  A1
#define R8  A2

#define leftButton 8
#define rightButton 10
#define upButton 13 
#define downButton 8

#define initialSpeed 1000

LEDmatrix matrix(datapin, clockpin, latchpin, R1, R2, R3, R4, R5, R6, R7, R8);
Position apple(0,0);
List snake;
SnakeGame game(leftButton, rightButton,upButton,downButton,matrix,snake,apple,initialSpeed);


Position newDirection(0,0); 
Position prevDirection(1,0);
Position forwardDirection(0,0);
List prevSnake;
Position prev1(1,1);
Position prev2(1,2);



void setup() {
  Serial.begin(115200);
  
  prevSnake.Append(prev1);
  prevSnake.Append(prev2);
  game.initialize();

}
  
void loop(){
  game.forward(prevDirection);
  game.updateDirection(newDirection);
  game.levelUp(prevSnake);
  
  prevSnake = game.getSnake();
  if(newDirection==forwardDirection){
    game.forward(prevDirection);
    game.levelUp(prevSnake);
    
  }
  else{
    game.turn(newDirection);
    game.levelUp(prevSnake);
    prevDirection = newDirection;
    
  }
  
}

// pause game
// game over 
// when you go right you cannot clic on left and vice versa
// when you go up you cannot clic down and vice versa