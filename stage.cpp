#include "stage.h"

Stage::Stage(Game *gm)
{
    game = gm;
}

void Stage::draw(){}
void Stage::handleKeys(){}

void Stage::run()
{
    handleKeys();
    draw();
    game->startSound->process();
    game->collisionSound->process();
    game->wrongSound->process();
    game->bangSound->process();
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
                game->startSound->stop();
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
        else if (ch == ENTER_KEY)
        {
            game->state = 2;
        }
    }
}

void IntroStage::draw()
{
    char roundStr[50] = "Round ";
    char buffer[50];
    strcat(roundStr, itoa(game->round, buffer, 10));

    game->drawHeader(roundStr);
    game->drawScore();
    
    setcolor(WHITE);
    line(85, 38, 560, 38);
    line(85, 40, 560, 40);
    line(85, 38, 85, 142);
    line(560, 38, 560, 142);

    outtextxy(100, 50, "Nihilistic letters are attacking the English Language!");
    outtextxy(100, 62, "They aim to destroy literacy with random words. Can you");
    outtextxy(100, 74, "stop the crazed letters and save your language?");

    outtextxy(100, 98, "Your strategy is to place your fingers on the home keys");
    outtextxy(100, 110, "('ASDF' and 'JKL;') and type the descending words before");
    outtextxy(100, 122, "they can cause cultural confusion");
    
    line(85, 140, 560, 140);
    line(85, 142, 560, 142);


    line(85, 170, 560, 170);
    line(85, 172, 560, 172);
    line(85, 170, 85, 264);
    line(560, 170, 560, 264);

    outtextxy(100, 182, "You score points for each word correctly typed. The");
    outtextxy(100, 194, "first letter of a word is worth 10 points, the second");
    outtextxy(100, 206, "letter adds 20 more, the third letter 30 more, etc. Each");
    outtextxy(100, 218, "miss deducts 10 points.");

    outtextxy(300, 242, "..Press Enter to begin Round 1.");

    line(85, 262, 560, 262);
    line(85, 264, 560, 264);

    game->drawBuildings();
    game->drawFooter();
}

void GameStage::handleKeys()
{
    if (kbhit())
    {
        int ch = getch();
        if (ch == ESC_KEY)
        {
            // exit the game temporarily
            // go to end score stage permanently
            game->gameEnd = 1;
            return;
        }

        if (selectedIndex < 0)
        {
            // no selected invader
            // check first letter from invaders
            for (int xx = 0; xx < spawnedInvadersCount; xx++)
            {
                if (
                    (AVAILABLE_LETTERS[spawnedInvadersArray[xx]].chars[0] == ch) && 
                    (invaders[spawnedInvadersArray[xx]]->selectedCount != AVAILABLE_LETTERS[spawnedInvadersArray[xx]].length))
                {
                    invaders[spawnedInvadersArray[xx]]->selectedCount += 1;

                    if (AVAILABLE_LETTERS[spawnedInvadersArray[xx]].length > 1)
                    {
                        selectedIndex = spawnedInvadersArray[xx];
                    }
                    else
                    {
                        invaders[spawnedInvadersArray[xx]]->showBullet = 1;
                    }
                    break;
                }
            }

            return;
        }

        // with selected invader
        if (AVAILABLE_LETTERS[selectedIndex].chars[invaders[selectedIndex]->selectedCount] == ch)
        {
            invaders[selectedIndex]->selectedCount += 1;
            if (invaders[selectedIndex]->selectedCount == AVAILABLE_LETTERS[selectedIndex].length)
            {
                invaders[selectedIndex]->showBullet = 1;
                selectedIndex = -1;
            }            
        }
        else
        {
            invaders[selectedIndex]->selectedCount = 0;
            selectedIndex = -1;
            game->wrongSound->play();
        }
    }
}

int GameStage::reduceValue(int thisLetterIndex, int value)
{
    while (value + AVAILABLE_LETTERS[thisLetterIndex].length > MAX_BUILDING)
    {
        value -= 1;
    }

    return value * X_PADDING;
}

void GameStage::spawnInvader()
{
    if (canSpawn() && spawnedInvadersCount < MAX_SPAWNED_INVADERS)
    {
        int letterIndex = -1;
        while (1)
        {
            letterIndex = game->getRandomNumber(0, AVAILABLE_LETTERS_COUNT - 1);

            if (!invaders[letterIndex]->isVisible)
            {
                invaders[letterIndex]->showBullet = 0;
                invaders[letterIndex]->bulletY = BUILDING_START_Y - X_PADDING;
                invaders[letterIndex]->selectedCount = 0;
                invaders[letterIndex]->isVisible = 1;
                invaders[letterIndex]->x = reduceValue(letterIndex, game->getRandomNumber(0, MAX_BUILDING - 1));
                invaders[letterIndex]->y = INVADER_DEFAULT_Y;
                break;
            }

            retry += 1;

            if (retry >= MAX_SPAWN_RETRY)
            {
                retry = 0;
                return;
            }
        }
        retry = 0;
        spawnedInvadersArray[spawnedInvadersCount] = letterIndex;
        spawnedInvadersCount += 1;   
    }
}

void GameStage::destroyBuildings(int invaderX, int lettersCount)
{
    int buildingIndex = invaderX / X_PADDING;
    for (int xx = 0; xx < lettersCount; xx++)
    {
        game->buildings[buildingIndex]->isBlown = 1;
        buildingIndex += 1;
    }
}

void GameStage::reAllignInvaders(int index)
{
    if (spawnedInvadersArray[index] == selectedIndex)
    {
        selectedIndex = -1;
    }

    invaders[spawnedInvadersArray[index]]->isVisible = 0;

    if (!invaders[spawnedInvadersArray[index]]->showBullet)
    {
        game->collisionSound->play();
        destroyBuildings(invaders[spawnedInvadersArray[index]]->x, AVAILABLE_LETTERS[invaders[spawnedInvadersArray[index]]->letterIndex].length);
    }
    else
    {
        game->bangSound->play();
    }

    for(int xx = index; xx < spawnedInvadersCount; xx++)
    {
        spawnedInvadersArray[xx] = spawnedInvadersArray[xx + 1];
    }
    spawnedInvadersCount -= 1;
}

void GameStage::drawInvaders()
{
    int indexToReAllign = -1;
    for(int xx = 0; xx < spawnedInvadersCount; xx++)
    {
        if ((invaders[spawnedInvadersArray[xx]]->y >= BUILDING_START_Y) || (invaders[spawnedInvadersArray[xx]]->y >= invaders[spawnedInvadersArray[xx]]->bulletY))
        {
           indexToReAllign = xx;
           continue;
        }
        invaders[spawnedInvadersArray[xx]]->draw();
    }

    if (indexToReAllign >= 0)
    {
        reAllignInvaders(indexToReAllign);
    }
}

void GameStage::draw()
{
    char roundStr[50] = "Round ";
    char buffer[50];
    strcat(roundStr, itoa(game->round, buffer, 10));

    game->drawHeader(roundStr);
    game->drawScore();

    spawnInvader();
    drawInvaders();

    game->drawBuildings();
}

GameStage::GameStage(Game *gm) 
    : Stage(gm), spawnTime(0), spawnedInvadersCount(0), retry(0), selectedIndex(-1)
{
    for(int xx = 0; xx < AVAILABLE_LETTERS_COUNT; xx++)
    {
        invaders[xx] = new Invader(xx);
    }
}

int GameStage::canSpawn()
{
    if (spawnTime >= SPAWN_TIME_TRIGGER)
    {
        spawnTime = 0;
        return 1;
    }

    spawnTime += 1;
    return 0;
}