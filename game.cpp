#include <graphics.h>
#include <conio.h>
#include "game.h"

Game::Game()
{
    state = 0;
    gameEnd = 0;
}

void Game::init()
{
    graphicDriver = VGA;
    graphicMode = VGAMED;
    initgraph(&graphicDriver, &graphicMode, BGI_PATH);
    maxX = getmaxx();
    maxY = getmaxy();
    setbkcolor(BLUE);

    titleStage = new Stage(this);
}

void Game::cleanup()
{
    closegraph();
    clrscr();
}

void Game::run()
{
    init();

    while(!gameEnd)
    {
		switch (state)
		{
		case 1:
			break;
		
		default:
            titleStage->run();
			break;
		}

    }

    cleanup();
}