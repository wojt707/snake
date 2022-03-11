
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

const int width{31};
const int height{15};
extern bool gameover;
extern int x, y, fruitX, fruitY;

void setup();
void draw();
void input();
void logic();
int randomNumber(int min, int max);

#endif