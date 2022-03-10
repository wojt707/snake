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
    fruitX = randomNumber(1, width - 2);
    fruitY = randomNumber(1, height - 2);
}
void draw()
{
    system("cls");

    std::cout << std::endl
              << "   ";
    for (int w = 0; w < width; w++)
        std::cout << '%';
    std::cout << std::endl;

    for (int h = 1; h < height - 1; h++)
    {
        std::cout << "   %";
        for (int w = 1; w < width-1; w++)
        {
            if (h == y && w == x)
            {
                std::cout << 'O';
            }
            else if (h == fruitY && w == fruitX)
            {
                std::cout << 'F';
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << '%' << std::endl;
    }
    std::cout << "   ";
    for (int w = 0; w < width; w++)
        std::cout << '%';
}
void input()
{
}
void logic()
{
}

int randomNumber(int min, int max)
{
    static bool first = true; // 
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % (max + 1 - min);
}