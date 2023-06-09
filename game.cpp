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
    startSoundStarted = 0;

    // intro sound
    int introSound[73] = {
        D5, -3, -1,
        G4, 0, 
        A4, 0, 
        B4, 0,
        C5, 0,
        D5, -2,
        G4, -2,
        G4, -3, -2,
        E5, -3, -1,
        C5, 0,
        D5, 0,
        E5, 0,
        F5, 0,
        G5, -2,
        G4, -2,
        G4, -3, -2,
        B4, -3, -1,
        C5, 0,
        B4, 0,
        A4, 0,
        G4, 0,
        A4, -3, -1,
        B4, 0,
        A4, 0,
        G4, 0,
        GB4, 0,
        G4, -3, -1,
        G4, 0,
        A4, 0,
        B4, 0,
        G4, 0,
        A4, -3, -1,
        -5,
    };
    startSound = new Sound(introSound, 1, 73);
    // end of intro sound

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
        { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
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
        { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
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
        { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 1, { D_HORIZONTAL } },
        { BUILDING_START_Y, 2, { D_DOWN_LEFT, D_UP_RIGHT } },
        { BUILDING_START_Y, 2, { D_DOWN_RIGHT, D_UP_LEFT } },
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

    /*
        I KNOW! I SHOULD'VE INCLUDE THE FOLLOWING CODE IN THE FOR STATEMENT ABOVE!
        BUT NO! IT'S NOT WORKING AND IT'S WEIRD!! HEHEHE!
    */
    for(int xx2 = 0; xx2 < MAX_BUILDING; xx2++)
    {
        buildings[xx2]->setBuildingChars(blocks[xx2].chars, blocks[xx2].length, blocks[xx2].startY);
    }
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
    gameStage = new GameStage(this);
}

void Game::cleanup()
{
    closegraph();
    clrscr();
    nosound();
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

        case 2:
            gameStage->run();
            break;
        
        default:
            if (!startSound->isPlaying() && !startSoundStarted)
            {
                startSoundStarted = 1;
                startSound->play();
            }
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
    setcolor(LIGHTCYAN);
    for(int xx = 0; xx < MAX_BUILDING; xx++)
    {
        buildings[xx]->draw();
    }   
}

int Game::getRandomNumber(int lowerBound, int upperBound)
{
    randomize();
    int ret = rand() % (upperBound + 1);

    while (ret < lowerBound)
    {
        ret = rand() % (upperBound + 1);
    }

    return ret;
}