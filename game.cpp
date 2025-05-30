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

    // intro sound
    startSound = new Sound(INTRO_SOUND, 1, INTRO_SOUND_LENGTH);
    // collision sound
    collisionSound = new Sound(COLLISION_SOUND, 0, COLLISION_SOUND_LENGTH);
    // wrong sound
    wrongSound = new Sound(WRONG_SOUND, 0, WRONG_SOUND_LENGTH);
    // bang sound
    bangSound = new Sound(BANG_SOUND, 0, BANG_SOUND_LENGTH);

    int counter = 0;
    for(int xx = 0; xx < MAX_BUILDING; xx++)
    {
        buildings[xx] = new Building(counter);
        counter += X_PADDING;
    }

    /*
        I KNOW! I SHOULD'VE INCLUDE THE FOLLOWING CODE IN THE FOR STATEMENT ABOVE!
        BUT NO! IT'S NOT WORKING AND IT'S WEIRD!! HEHEHE!
    */
    for(int xx2 = 0; xx2 < MAX_BUILDING; xx2++)
    {
        buildings[xx2]->setBuildingChars(BUILDING_BLOCKS[xx2].chars, BUILDING_BLOCKS[xx2].length, BUILDING_BLOCKS[xx2].startY);
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
            if (!startSound->isPlaying())
            {
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
    outtextxy((maxX / 2) - 83, maxY - 10, GAME_TITLE);
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