
#ifndef snakeLibrary_h
#define snakeLibrary_h

enum direction
{
    stop = 0,
    up,
    down,
    left,
    right
};

const int width{51};
const int height{21};
extern bool gameover;
extern int x, y, fruitX, fruitY;

void setup();
void draw();
void input();
void logic();
int randomNumber(int min, int max);

#endif