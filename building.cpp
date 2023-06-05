#include "building.h"
#include <graphics.h>
#include <string.h>

Building::Building(int ex)
{
    x = ex;
    isBlown = 0;
    buildingCount = 0;
}

void Building::setBuildingChars(struct BuildingChar bChars[])
{
    for (int xx=0; xx < sizeof(bChars); xx++)
    {
        buildingChars[xx] = bChars[xx];
        buildingCount += 1;
    }
}

void Building::draw()
{
    if (!isBlown)
    {
        int thisY = BUILDING_START_Y;
        char buffer[2];

        for (int xx=0; xx < buildingCount; x++)
        {
            char str[2] = { (char) buildingChars->charInt, '\0' };
            strcpy(buffer, str);
            outtextxy(x, thisY, buffer);

            thisY += 8;
        }
    }
}