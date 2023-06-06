#ifndef _BUILDING_H_
#define _BUILDING_H_

#define BUILDING_START_Y 296
#define D_VERTICAL 186
#define D_DOWN_LEFT 187
#define D_UP_LEFT 188
#define D_UP_RIGHT 200
#define D_DOWN_RIGHT 201
#define D_HORIZONTAL 205
#define SPACE 255

struct Block {
    int startY;
    int length;
    int chars[10];
};

class Building {
    public:
        int isBlown;
        int x;
        int buildingCount;
        int startY;
        int intChars[];
        Building(int ex);
        void setBuildingChars(int thisIntChars[], int bCount, int sY);
        void draw();
};

#endif