#include "stage.h"
#include <conio.h>
#include <graphics.h>

Stage::Stage(Game *gm)
{
    game = gm;
}

void Stage::run()
{
    handleKeys();
    draw();
}

void TitleStage::handleKeys()
{
    if (kbhit())
    {
        int ch = getch();
        if (ch == ESC_KEY)
        {
            game->gameEnd = 1;
        }
        else if (ch == TAB_KEY)
        {
            game->selectedOption = (game->selectedOption == 0)? 1 : 0;
        }
        else if (ch == ENTER_KEY)
        {
            if (game->selectedOption == 1)
            {
                game->gameEnd = 1;
            }
            else
            {
                game->state = 1;
            }
        }
    }
}

void TitleStage::draw()
{
    int pluser;

    //draw shits
    game->drawHeader("Recreated by: six519");

    line(80, 80, game->maxX - 80, 80);
    line(80, 82, game->maxX - 80, 82);
    line(80, 80, 80, game->maxY - 80);
    line(game->maxX - 80, 80, game->maxX - 80, game->maxY - 80);
    line(80, game->maxY - 80, game->maxX - 80, game->maxY - 80);
    line(80, game->maxY - 82, game->maxX - 80, game->maxY - 82);

    setcolor(GREEN);
    rectangle(263, 145, game->maxX - 263, 202);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(264, 146, GREEN);

    setcolor(WHITE);
    line(265, 150, game->maxX - 265, 150);
    line(265, 152, game->maxX - 265, 152);
    line(265, 150, 265, 197);
    line(game->maxX - 265, 150, game->maxX - 265, 197);
    line(265, 195, game->maxX - 265, 195);
    line(265, 197, game->maxX - 265, 197);

    outtextxy(100, 100, "Press Tab to choose an option..");
    outtextxy(220, game->maxY - 100, "..press Enter to select highlighted item.");

    setcolor(BLUE);
    pluser = (game->selectedOption == 0)? 0 : 20;
    rectangle(267, 158 + pluser, game->maxX - 267, 168 + pluser);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(268, 159 + pluser, BLUE);

    //start game
    setcolor((game->selectedOption == 0)? LIGHTGREEN : LIGHTBLUE);
    outtextxy((game->maxX / 2) - 40, 160, "Start Game");
    setcolor((game->selectedOption == 0)? LIGHTBLUE : LIGHTGREEN);
    outtextxy((game->maxX / 2) - 36, 180, "Quit Game");

    game->drawFooter();
}

void IntroStage::handleKeys()
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

void IntroStage::draw()
{

}