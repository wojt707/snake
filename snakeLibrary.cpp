#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "snakeLibrary.h"

bool gameover;
int score;
coordinates head, fruit;
std::vector<coordinates> tail;
direction _direction;

void setup()
{
    gameover = false;
    score = 0;
    _direction = stop;
    head.x = width / 2;
    head.y = height / 2;
    tail.clear();
    fruit.x = randomNumber(1, width - 2);
    fruit.y = randomNumber(1, height - 2);
}

void draw()
{
    system("cls");

    std::cout << "\n   ";
    for (int w = 0; w < width; w++)
        std::cout << '%';
    std::cout << '\n';

    for (int h = 1; h < height - 1; h++)
    {
        std::cout << "   %";
        for (int w = 1; w < width - 1; w++)
        {
            if (h == head.y && w == head.x)
            {
                std::cout << 'O';
                continue;
            }

            if (h == fruit.y && w == fruit.x)
            {
                std::cout << fruitSymbol;
                continue;
            }

            bool isTail = false;
            for (auto &&tailPiece : tail)
                if (h == tailPiece.y && w == tailPiece.x)
                {
                    isTail = true;
                    break;
                }
            char c = (isTail) ? 'o' : ' ';
            std::cout << c;
        }
        std::cout << "%\n";
    }

    std::cout << "   ";
    for (int w = 0; w < width; w++)
        std::cout << '%';

    std::cout << "\n\n   SCORE: " << score;
}

void input()
{
    if (kbhit())
        switch (getch())
        {
        case 'w':
            _direction = (_direction == down) ? down : up;
            break;
        case 'a':
            _direction = (_direction == right) ? right : left;
            break;
        case 's':
            _direction = (_direction == up) ? up : down;
            break;
        case 'd':
            _direction = (_direction == left) ? left : right;
            break;
        case 27:
            gameover = true;
            break;
        }
}

void logic()
{
    if (tail.size())
    {
        for (int i = tail.size() - 1; i > 0; i--)
            tail[i] = tail[i - 1];
        tail[0] = head;
    }
    switch (_direction)
    {
    case up:
        head.y--;
        Sleep(70);
        break;
    case down:
        head.y++;
        Sleep(70);
        break;
    case left:
        head.x--;
        Sleep(20);
        break;
    case right:
        head.x++;
        Sleep(20);
        break;
    }
    if (head.x == 0)
        head.x = width - 2;
    else if (head.x == width - 1)
        head.x = 1;
    if (head.y == 0)
        head.y = height - 2;
    else if (head.y == height - 1)
        head.y = 1;
    if (head.x == fruit.x && head.y == fruit.y)
    {
        score += 1;
        fruit.x = randomNumber(1, width - 2);
        fruit.y = randomNumber(1, height - 2);
        coordinates tailEnd;
        tail.push_back(tailEnd);
    }
    for (auto &&tailPiece : tail)
        if (head.x == tailPiece.x && head.y == tailPiece.y)
            gameover = true;
}

int randomNumber(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % (max + 1 - min);
}
