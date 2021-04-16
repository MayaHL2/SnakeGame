#include<SnakeGame.h>

SnakeGame :: SnakeGame(int leftButton,int rightButton, int upButton,int downButton,LEDmatrix matrix, List snake, Position apple): leftButton(leftButton), rightButton(rightButton), upButton(upButton), downButton(downButton), matrix(matrix),snake(snake),apple(apple)
{} 

SnakeGame ::~SnakeGame(){}

void SnakeGame :: initialize(){
    pinMode(leftButton,INPUT);
    pinMode(rightButton,INPUT);
    pinMode(upButton,INPUT);
    pinMode(downButton,INPUT);
    matrix.initialize();

    List temp;
    Position initial(1,1);
    randomApple();
    temp.Append(initial); 
    snake = temp;
    turnOnGame();
}


void SnakeGame :: forward(Position directionPrev){
    snake.move(directionPrev);
    turnOnGame();
}

void SnakeGame ::turn(Position direction){
    snake.move(direction);
    turnOnGame();
}

void SnakeGame ::updateDirection(Position& directionSnake){
    directionSnake.update(0,0);
    if(digitalRead(leftButton)){
        directionSnake.update(-1,0);
    }
    else if (digitalRead(rightButton)){
        directionSnake.update(1,0);
    }
    else if (digitalRead(upButton)){
        directionSnake.update(0,1);
    }    
    else if (digitalRead(downButton)){
        directionSnake.update(0,-1);
    }
}

void SnakeGame::updateSnake(List snakePrev){
    snake.Append(snakePrev.Last());
    turnOnGame();
}

void SnakeGame::turnOnGame(){
    List temp = snake; 
    temp.Append(apple);
    matrix.turnOnLEDs(temp);
}

void SnakeGame::randomApple(){
    randomSeed(analogRead(A0));
    Position tempApple(random(1,matrixLen),random(1,matrixLen));
    while (snake.Search(tempApple))
    {
        tempApple.update(random(1,matrixLen),random(1,matrixLen));
    }
    apple = tempApple;
}

bool SnakeGame::eatApple(){
    return snake.First()==apple;
}

List SnakeGame::getSnake(){
    return snake;
}