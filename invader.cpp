#include "invader.h"

Invader::Invader(int letterIndex)
    : x(0), y(INVADER_DEFAULT_Y), letterIndex(letterIndex), isVisible(0)
{

}

void Invader::draw()
{
    if (isVisible)
    {
        setcolor(WHITE);
        outtextxy(x, y, AVAILABLE_LETTERS[letterIndex]);
        y += INVADER_SPEED;
    }
}