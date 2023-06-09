#include "building.h"

Building::Building(int ex)
{
    x = ex;
    isBlown = 0;
    buildingCount = 0;
    startY = 0;
}

void Building::setBuildingChars(int thisIntChars[], int bCount, int sY)
{
    buildingCount = bCount;
    startY = sY;
    for (int xx = 0; xx < buildingCount; xx++)
    {
        intChars[xx] = thisIntChars[xx];
    }
}

void Building::draw()
{
    if (!isBlown)
    {
        int thisY = startY;
        char buffer[2];

        for (int xx=0; xx < buildingCount; xx++)
        {
            char str[2] = { (char) intChars[xx], '\0' };
            strcpy(buffer, str);
            outtextxy(x, thisY, buffer);

            thisY += 8;
        }
    }
}