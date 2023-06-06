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

    struct Block blocks[80] = {
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },

        { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
        { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
        { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },

        { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
        { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
        { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },

        { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y + 8, 1, { D_HORIZONTAL } },
    };

    int counter = 0;
    for(int xx = 0; xx < MAX_BUILDING; xx++)
    {
        buildings[xx] = new Building(counter);
        counter += 8;
    }

    /**
    buildings[0]->setBuildingChars(blocks[0].chars, blocks[0].length, blocks[0].startY);
    buildings[1]->setBuildingChars(blocks[1].chars, blocks[1].length, blocks[1].startY);
    buildings[2]->setBuildingChars(blocks[2].chars, blocks[2].length, blocks[2].startY);
    buildings[3]->setBuildingChars(blocks[3].chars, blocks[3].length, blocks[3].startY);
    buildings[4]->setBuildingChars(blocks[4].chars, blocks[4].length, blocks[4].startY);
    buildings[5]->setBuildingChars(blocks[5].chars, blocks[5].length, blocks[5].startY);
    buildings[6]->setBuildingChars(blocks[6].chars, blocks[6].length, blocks[6].startY);
    buildings[7]->setBuildingChars(blocks[7].chars, blocks[7].length, blocks[7].startY);
    buildings[8]->setBuildingChars(blocks[8].chars, blocks[8].length, blocks[8].startY);

    buildings[9]->setBuildingChars(blocks[9].chars, blocks[9].length, blocks[9].startY);
    buildings[10]->setBuildingChars(blocks[10].chars, blocks[10].length, blocks[10].startY);
    buildings[11]->setBuildingChars(blocks[11].chars, blocks[11].length, blocks[11].startY);
    buildings[12]->setBuildingChars(blocks[12].chars, blocks[12].length, blocks[12].startY);
    buildings[13]->setBuildingChars(blocks[13].chars, blocks[13].length, blocks[13].startY);
    buildings[14]->setBuildingChars(blocks[14].chars, blocks[14].length, blocks[14].startY);
    buildings[15]->setBuildingChars(blocks[15].chars, blocks[15].length, blocks[15].startY);

    buildings[16]->setBuildingChars(blocks[16].chars, blocks[16].length, blocks[16].startY);
    buildings[17]->setBuildingChars(blocks[17].chars, blocks[17].length, blocks[17].startY);
    buildings[18]->setBuildingChars(blocks[18].chars, blocks[18].length, blocks[18].startY);
    buildings[19]->setBuildingChars(blocks[19].chars, blocks[19].length, blocks[19].startY);
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