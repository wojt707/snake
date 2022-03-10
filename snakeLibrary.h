
#ifndef snakeLibrary_h
#define snakeLibrary_h

const int width{20};
const int height{20};
extern bool gameover;
extern int x, y;

void setup();
void draw();
void input();
void logic();

#endif