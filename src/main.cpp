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
#define R6  8
#define R7  10
#define R8  13

#define leftButton 8
#define rightButton 8
#define upButton 8
#define downButton 8


LEDmatrix matrix(datapin, clockpin, latchpin, R1, R2, R3, R4, R5, R6, R7, R8);
Position apple(0,0);
List snake;
SnakeGame game(leftButton, rightButton,upButton,downButton,matrix,snake,apple);


Position newDirection(0,0); 
Position prevDirection(1,0);
Position initialCond(0,0);
List prevSnake;

void setup() {
  Serial.begin(115200);
  game.initialize();
  Serial.println("Hey");

}
  
void loop(){
  
game.updateDirection(newDirection);
prevSnake = game.getSnake();
if(newDirection==initialCond){
  game.forward(prevDirection);
}
else{
  game.turn(newDirection);
  prevDirection = newDirection;
}
if(game.eatApple()){
  game.updateSnake(prevSnake);
  game.randomApple();
}
}

// List et Positions sont complètes et correctes