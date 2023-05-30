#ifndef _GAME_H_
#define _GAME_H_
#include "stage.h"

#define BGI_PATH "C:\\TC\\BGI"
#define GAME_DELAY 9

#define ESC_KEY 27
#define TAB_KEY 9
#define ENTER_KEY 13

class TitleStage;
class IntroStage;

class Game
{
    private:
        void init();
        int graphicDriver;
        int graphicMode;
        TitleStage *titleStage;
        IntroStage *introStage;
        int visualPage;
        int activePage;
        void changePage();
    public:
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
};

#endif