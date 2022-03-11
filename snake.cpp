#include <iostream>
#include "snakeLibrary.h"

int main(int argc, char const *argv[])
{
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
    }
    return 0;
}
