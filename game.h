#ifndef _GAME_H_
#define _GAME_H_
#include "stage.h"

#define BGI_PATH "C:\\TC\\BGI"
#define GAME_DELAY 9

#define ESC_KEY 27
#define TAB_KEY 9
#define ENTER_KEY 13

class Stage;

class Game
{
    private:
        void init();
        int graphicDriver;
        int graphicMode;
        int state;
        Stage *titleStage;
        int visualPage;
        int activePage;
        void changePage();
    public:
        int selectedOption;
        int gameEnd;
        int maxX;
        int maxY;
        Game();
        void run();
        void cleanup();
};

#endif