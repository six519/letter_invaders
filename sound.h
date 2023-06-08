#ifndef _SOUND_H_
#define _SOUND_H_
#include <dos.h>
#include <stdlib.h>

#define D5 587
#define G4 392
#define A4 440
#define B4 494
#define C5 523
#define E5 659
#define D5 587
#define F5 698
#define G5 784
#define GB4 370 

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