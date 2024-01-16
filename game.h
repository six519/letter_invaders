#ifndef _GAME_H_
#define _GAME_H_
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include "stage.h"
#include "building.h"
#include "sound.h"

#define BGI_PATH "C:\\TC\\BGI"
#define GAME_DELAY 9
#define GAME_TITLE "Letter Invaders 2024"

#define ESC_KEY 27
#define TAB_KEY 9
#define ENTER_KEY 13

class TitleStage;
class IntroStage;
class GameStage;

class Game
{
    private:
        void init();
        int graphicDriver;
        int graphicMode;
        TitleStage *titleStage;
        IntroStage *introStage;
        GameStage *gameStage;
        int visualPage;
        int activePage;
        void changePage();
        Building *buildings[MAX_BUILDING];
    public:
        Sound *startSound;
        Sound *collisionSound;
        int selectedOption;
        int gameEnd;
        int maxX;
        int maxY;
        int round;
        int state;
        int score;
        Game();
        void run();
        void cleanup();
        void drawHeader(char txt[]);
        void drawFooter();
        void drawScore();
        void drawBuildings();
        int getRandomNumber(int lowerBound, int upperBound);
};

#endif