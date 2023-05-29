#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include "game.h"

Game::Game()
{
    state = 0;
    gameEnd = 0;
    visualPage = 0;
    activePage = 1;
    selectedOption = 0;
}

void Game::init()
{
    graphicDriver = VGA;
    graphicMode = VGAMED;
    initgraph(&graphicDriver, &graphicMode, BGI_PATH);
    maxX = getmaxx();
    maxY = getmaxy();
    setbkcolor(BLUE);

    titleStage = new TitleStage(this);
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

        changePage();
    }

    cleanup();
}

void Game::changePage()
{
    //set page
    visualPage = (visualPage == 1)? 0 : 1;
    activePage = (activePage == 1)? 0 : 1;
    setvisualpage(visualPage);
    setactivepage(activePage);
    delay(GAME_DELAY);
    cleardevice();
}