#include "stage.h"
#include <conio.h>
#include <graphics.h>

Stage::Stage(Game *gm)
{
    game = gm;
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
    setcolor(WHITE);
    outtextxy(5, 8, "Recreated by: six519");
    line(0, 20, game->maxX, 20);
    line(0, 22, game->maxX, 22);
}

void Stage::run()
{
    handleKeys();
    draw();
}