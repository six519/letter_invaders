#ifndef _BUILDING_H_
#define _BUILDING_H_

struct BuildingChar{
    int charInt;
    int y;
};

class Building {
    public:
        int isBlown;
        int x;
        struct BuildingChar buildingChars[];
        Building(struct BuildingChar bChars[], int ex);
};

#endif