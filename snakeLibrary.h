
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

const int width{50};
const int height{20};
extern bool gameover;
extern int x, y, fruitX, fruitY;

void setup();
void draw();
void input();
void logic();
int random(const int minimum, const int maximum);

#endif