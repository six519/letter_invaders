#ifndef _GAME_H_
#define _GAME_H_
#define TARGET_FPS 35
#define FRAME_SPEED 5
#define BGI_PATH "C:\\TC\\BGI"

#define ESC_KEY 27

class Game
{
	private:
        void init();
        int graphicDriver;
        int graphicMode;
	public:
        Game();
		void run();
        void cleanup();
};

#endif