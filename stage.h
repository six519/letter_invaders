#ifndef _STAGE_H_
#define _STAGE_H_
#include "game.h"

class Game;

class Stage
{	
    protected:
        Game *game;
        virtual void handleKeys();
        virtual void draw();
    public:
        Stage(Game *gm);
        void run();
};

class TitleStage: public Stage
{
    protected:
        void handleKeys();
        void draw();
    public:
        TitleStage(Game *gm) : Stage(gm){}
};

#endif