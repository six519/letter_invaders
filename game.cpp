#include <graphics.h>
#include <conio.h>
#include "game.h"

Game::Game()
{

}

void Game::init()
{
    graphicDriver = DETECT;
    graphicMode = 0;
    initgraph(&graphicDriver, &graphicMode, BGI_PATH);
}

void Game::cleanup()
{
    closegraph();
    clrscr();
}

void Game::run()
{
    int gameEnd = 0;
    init();

    while(!gameEnd)
    {
        if (kbhit())
        {
            int ch = getch();
            if (ch == ESC_KEY)
            {
                gameEnd = 1;
                break;
            }
        }

    }

    cleanup();
}