#include <iostream>
#include "snakeLibrary.h"

int main(int argc, char const *argv[])
{

    std::cout << gameover << std::endl;
    setup();
    std::cout << gameover << std::endl;
    std::cout<< "snake.cpp " << height << std::endl;
    draw();
    input();
    logic();
    return 0;
}
