#ifndef SnakeGame_cpp
#define SnakeGame_cpp

#include<LEDmatrix.h>


class SnakeGame
{
private:
    int leftButton;
    int rightButton;
    int upButton;
    int downButton;
    LEDmatrix matrix;
    List snake;
    Position apple;
public:
    SnakeGame(int leftButton,int rightButton, int upButton,int downButton,LEDmatrix matrix, List snake, Position apple);
    ~SnakeGame();
    void initialize();
    List getSnake();
    void forward(Position direction);//snake goes forward
    void turn(Position direction);//snake turns depending on the direction
    void updateDirection(Position&);//direction that the snake should take depending on the values of the buttons
    void updateSnake(List snakePrev);//update the length of the snake
    void randomApple();//positioning the apple
    void turnOnGame();//turning on the matrix with a picture of the game
    bool eatApple();// is the head of the snake on top of the apple
};

 
#endif