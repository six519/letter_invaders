#include "building.h"

Building::Building(int ex)
{
    x = ex;
    isBlown = 0;
}

void Building::setBuildingChars(struct BuildingChar bChars[])
{
    for (int xx=0; xx < sizeof(bChars); xx++)
    {
        buildingChars[xx] = bChars[xx];
    }
}