#include "invader.h"

Invader::Invader(int letterIndex)
    : x(0), y(INVADER_DEFAULT_Y), letterIndex(letterIndex), isVisible(0), moveTime(0)
{

}

int Invader::canMove()
{
    if (moveTime >= INVADER_MOVE_TRIGGER)
    {
        moveTime = 0;
        return 1;
    }

    moveTime += 1;
    return 0;
}

void Invader::draw()
{
    if (isVisible)
    {
        setcolor(WHITE);
        outtextxy(x, y, AVAILABLE_LETTERS[letterIndex]);

        if (canMove())
        {
            y += INVADER_SPEED;
        }
    }
}