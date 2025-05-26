#include "invader.h"

Invader::Invader(int letterIndex)
    : x(0), y(INVADER_DEFAULT_Y), letterIndex(letterIndex), isVisible(0), moveTime(0), selectedCount(0), bulletY(BUILDING_START_Y - X_PADDING), showBullet(0)
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
    if (!isVisible)
        return;

    int thisX = this->x;
    int thisCount = 1;

    for (int xx = 0; xx < AVAILABLE_LETTERS[letterIndex].length; xx++)
    {
        char individualChar[2] = { AVAILABLE_LETTERS[letterIndex].chars[xx], '\0'};
        if (thisCount <= selectedCount) 
        {
            setcolor(LIGHTGREEN);
        }
        else
        {
            setcolor(WHITE);
        } 
        outtextxy(thisX, y, individualChar);
        thisX += X_PADDING;
        thisCount += 1;
    }

    if (canMove())
    {
        y += INVADER_SPEED;
    }

    if (showBullet)
    {
        // draw bullet
        int centeredX = this->x + ((AVAILABLE_LETTERS[letterIndex].length * X_PADDING) - X_PADDING) / 2;
        setcolor(LIGHTRED);
        char c[2] = { (char)BULLET_CHAR, '\0' };
        outtextxy(centeredX, bulletY, c);
        bulletY -= INVADER_SPEED + 5;
    }
}