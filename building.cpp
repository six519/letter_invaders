#include "building.h"

Building::Building(struct BuildingChar bChars[], int ex)
{
    x = ex;
    isBlown = 0;

    for (int xx=0; xx < sizeof(bChars); xx++)
    {
        buildingChars[xx] = bChars[xx];
    }
}