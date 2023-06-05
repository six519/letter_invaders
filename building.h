#ifndef _BUILDING_H_
#define _BUILDING_H_

#define BUILDING_START_Y 296

struct BuildingChar{
    int charInt;
    int y;
};

class Building {
    public:
        int isBlown;
        int x;
        struct BuildingChar buildingChars[];
        Building(int ex);
        void setBuildingChars(struct BuildingChar bChars[]);
};

#endif