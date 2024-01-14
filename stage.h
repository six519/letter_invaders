#ifndef _STAGE_H_
#define _STAGE_H_
#include <conio.h>
#include <graphics.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"
#include "invader.h"

#define MAX_SPAWNED_INVADERS 10

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

class IntroStage: public Stage
{
    protected:
        void handleKeys();
        void draw();
    public:
        IntroStage(Game *gm) : Stage(gm){}
};

class GameStage: public Stage
{
    protected:
        void handleKeys();
        void draw();
    public:
        GameStage(Game *gm);
        Invader *invaders[AVAILABLE_LETTERS_COUNT];
        int spawnedInvadersCount;
        int spawnedInvadersArray[MAX_SPAWNED_INVADERS];
};

#endif