#include "stage.h"
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>

Stage::Stage(Game *gm)
{
    game = gm;
    visualPage = 0;
    activePage = 1;
}

void Stage::handleKeys()
{
    if (kbhit())
    {
        int ch = getch();
        if (ch == ESC_KEY)
        {
            game->gameEnd = 1;
        }
    }
}

void Stage::draw()
{
    //draw shits
    setcolor(WHITE);
    outtextxy(5, 8, "Recreated by: six519");
    line(0, 20, game->maxX, 20);
    line(0, 22, game->maxX, 22);

    //set page
    visualPage = (visualPage == 1)? 0 : 1;
    activePage = (activePage == 1)? 0 : 1;
    setvisualpage(visualPage);
    setactivepage(activePage);
    delay(GAME_DELAY);
    cleardevice();
}

void Stage::run()
{
    handleKeys();
    draw();
}