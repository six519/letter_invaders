#ifndef _BUILDING_H_
#define _BUILDING_H_

#define BUILDING_START_Y 296

class Building {
    public:
        int isBlown;
        int x;
        int buildingCount;
        int intChars[];
        Building(int ex);
        void setBuildingChars(int thisIntChars[], int bCount);
        void draw();
};

#endif