#include "building.h"

Building::Building(struct BuildingChar bChars[], int ex)
{
    x = ex;
    isBlown = 0;

    for (int x=0; x < sizeof(bChars); x++)
    {
        buildingChars[x] = bChars[x];
    }
}