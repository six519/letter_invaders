#ifndef _STAGE_H_
#define _STAGE_H_
#include "game.h"

class Game;

class Stage
{	
    private:
        Game *game;
    public:
        Stage(Game *gm);
        void run();
        void handleKeys();
        void draw();
};

#endif