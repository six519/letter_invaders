#ifndef _SOUND_H_
#define _SOUND_H_
#include <dos.h>

class Sound
{
    private:
        int isLooping;
        int notesList[];
        int isPlaying;
        int noteCount;
    public:
        Sound(int notes[], int isLoop, int nCount);
        void process();
        void play();
        void stop();
};

#endif