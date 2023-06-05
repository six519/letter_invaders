#ifndef _BUILDING_H_
#define _BUILDING_H_

#define BUILDING_START_Y 296

struct BuildingChar{
    int charInt;
};

class Building {
    public:
        int isBlown;
        int x;
        int buildingCount;
        struct BuildingChar buildingChars[];
        Building(int ex);
        void setBuildingChars(struct BuildingChar bChars[]);
        void draw();
};

#endif