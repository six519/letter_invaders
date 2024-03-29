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
        int thisX = this->x;
        for (int xx = 0; xx < AVAILABLE_LETTERS[letterIndex].length; xx++)
        {
            char individualChar[2] = { AVAILABLE_LETTERS[letterIndex].chars[xx], '\0'};
            setcolor(WHITE);
            outtextxy(thisX, y, individualChar);
            thisX += X_PADDING;
        }

        if (canMove())
        {
            y += INVADER_SPEED;
        }
    }
}