#ifndef _BUILDING_H_

#define _BUILDING_H_
#include <graphics.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUILDING_START_Y 320
#define D_VERTICAL 186
#define D_DOWN_LEFT 187
#define D_UP_LEFT 188
#define D_UP_RIGHT 200
#define D_DOWN_RIGHT 201
#define D_HORIZONTAL 205
#define SPACE 255
#define MAX_BUILDING 80
#define X_PADDING 8

struct Block {
    int startY;
    int length;
    int chars[2];
};

static struct Block BUILDING_BLOCKS[MAX_BUILDING] = {
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
    { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
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