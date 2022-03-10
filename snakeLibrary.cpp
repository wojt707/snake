#include <iostream>
#include <random>
#include <chrono>
#include "snakeLibrary.h"

bool gameover;
int x, y, fruitX, fruitY;
direction dir;
void setup()
{
    gameover = false;
    dir = stop;
    x = width / 2;
    y = height / 2;
    fruitX = random(0, width);
    fruitY = random(0, height);
}
void draw()
{
    system("cls");
    // while (!gameover)
    {
        std::cout << std::endl;
        for (int h = 0; h < height; h++)
        {
            std::cout << "   ";
            for (int w = 0; w < width; w++)
            {
                char c = ((w == 0 || w == width - 1) || (h == 0 || h == height - 1)) ? '%' : ' ';
                std::cout << c;
            }
            std::cout << std::endl;
        }
    }
}
void input()
{
}
void logic()
{
}
int random(const int minimum, const int maximum)
{
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distro(minimum, maximum);
    return distro(engine);
}