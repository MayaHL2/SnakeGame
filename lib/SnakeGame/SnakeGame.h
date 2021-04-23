#ifndef SnakeGame_cpp
#define SnakeGame_cpp

#include<LEDmatrix.h>

#define speedDecay 10

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
    int actualSpeed;
public:
    SnakeGame(int leftButton,int rightButton, int upButton,int downButton,LEDmatrix matrix, List snake, Position apple, int initialSpeed);
    ~SnakeGame();
    void initialize();
    List getSnake();
    void forward(Position);//snake goes forward
    void turn(Position);//snake turns depending on the direction
    void updateDirection(Position&);//direction that the snake should take depending on the values of the buttons
    void updateSnake(List);//update the length of the snake
    void randomApple();//positioning the apple
    void turnOnGame();//turning on the matrix with a picture of the game
    bool eatApple();// is the head of the snake on top of the apple
    void updateSpeed(); //updates the speed of the snake and makes it go quicker
    void levelUp(List snakePrev); //if apple was eaten updates the snake, the apple and the speed
    bool correctNewDirection(); //if leftButton is activated makes sure snake is not going right and vice versa (same with up and down)
};

 
#endif