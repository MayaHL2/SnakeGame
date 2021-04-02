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
public:
    SnakeGame(/* args */);
    ~SnakeGame();
};


#endif