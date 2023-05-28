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
    //draw shits
    setcolor(WHITE);
    outtextxy(5, 8, "Recreated by: six519");
    line(0, 20, game->maxX, 20);
    line(0, 22, game->maxX, 22);

    line(80, 80, game->maxX - 80, 80);
    line(80, 82, game->maxX - 80, 82);
    line(80, 80, 80, game->maxY - 80);
    line(game->maxX - 80, 80, game->maxX - 80, game->maxY - 80);
    line(80, game->maxY - 80, game->maxX - 80, game->maxY - 80);
    line(80, game->maxY - 82, game->maxX - 80, game->maxY - 82);

    outtextxy(100, 100, "Choose an option..");
    outtextxy(220, game->maxY - 100, "..press Enter to select highlighted item.");

    setcolor(LIGHTMAGENTA);
    rectangle(0, game->maxY - 16, game->maxX, game->maxY);
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    floodfill(5, game->maxY - 15, LIGHTMAGENTA);
    setcolor(YELLOW);
    outtextxy((game->maxX / 2) - 60, game->maxY - 10, "Esc -> Game Exit");
}

void Stage::run()
{
    handleKeys();
    draw();
}