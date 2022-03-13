
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

struct coordinates
{
    int x;
    int y;
};

const int width{15};
const int height{11};
const char fruitSymbol{3};
extern bool gameover;

void setup();
void draw();
void input();
void logic();
int randomNumber(int min, int max);

#endif
