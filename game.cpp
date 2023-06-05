#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

Game::Game()
{
    state = 0;
    gameEnd = 0;
    visualPage = 0;
    activePage = 1;
    selectedOption = 0;
    round = 1;
    score = 0;

    int counter = 0;
    for(int xx = 0; xx < MAX_BUILDING; xx++)
    {
        buildings[xx] = new Building(counter);
        counter += 8;
    }

    /*
    int test[] = { 205 };
    int test2[] = { 187, 186 };
    buildings[0]->setBuildingChars(test, 1);
    buildings[1]->setBuildingChars(test, 1);
    buildings[2]->setBuildingChars(test2, 2);
    */
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
    introStage = new IntroStage(this);
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
            introStage->run();
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

void Game::drawHeader(char txt[])
{
    setcolor(WHITE);
    outtextxy(5, 8, txt);
    line(0, 20, maxX, 20);
    line(0, 22, maxX, 22);
}

void Game::drawFooter()
{
    setcolor(LIGHTMAGENTA);
    rectangle(0, maxY - 16, maxX, maxY);
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    floodfill(5, maxY - 15, LIGHTMAGENTA);
    setcolor(YELLOW);
    outtextxy((maxX / 2) - 83, maxY - 10, "Letter Invaders 2023");
}

void Game::drawScore()
{
    char scoreStr[50] = "Score: ";
    char buffer[50];
    strcat(scoreStr, itoa(score, buffer, 10));
    setcolor(YELLOW);
    outtextxy((maxX / 2) - ((strlen(scoreStr) * 13) / 2), 8, scoreStr);
}

void Game::drawBuildings()
{
    setcolor(CYAN);
    for(int xx = 0; xx < MAX_BUILDING; xx++)
    {
        buildings[xx]->draw();
    }   
}