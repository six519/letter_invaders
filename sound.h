#ifndef _SOUND_H_
#define _SOUND_H_
#include <dos.h>
#include <stdlib.h>

class Sound
{
    private:
        int isLooping;
        int notesList[500];
        int isPlay;
        int noteCount;
        int currentNote;
        int timer;
        void nextNote();
    public:
        Sound(int notes[], int isLoop, int nCount);
        void process();
        void play();
        void stop();
        int isPlaying();
};

#endif