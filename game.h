#ifndef _GAME_H_
#define _GAME_H_
#include "stage.h"

#define TARGET_FPS 35
#define FRAME_SPEED 5
#define BGI_PATH "C:\\TC\\BGI"

#define ESC_KEY 27

class Stage;

class Game
{
	private:
        void init();
        int graphicDriver;
        int graphicMode;
        int state;
        Stage *titleStage;
	public:
        int gameEnd;
        int maxX;
        int maxY;
        Game();
        void run();
        void cleanup();
};

#endif