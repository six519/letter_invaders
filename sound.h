#ifndef _SOUND_H_
#define _SOUND_H_
#include <dos.h>
#include <stdlib.h>

#define G3 196
#define G6 1567
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

#define INTRO_SOUND_LENGTH 73
#define COLLISION_SOUND_LENGTH 4

static int COLLISION_SOUND[COLLISION_SOUND_LENGTH] = {
    G3,
    G4,
    G5,
    G6,
};

static int INTRO_SOUND[INTRO_SOUND_LENGTH] = {
    D5, -3, -1,
    G4, 0, 
    A4, 0, 
    B4, 0,
    C5, 0,
    D5, -2,
    G4, -2,
    G4, -3, -2,
    E5, -3, -1,
    C5, 0,
    D5, 0,
    E5, 0,
    F5, 0,
    G5, -2,
    G4, -2,
    G4, -3, -2,
    B4, -3, -1,
    C5, 0,
    B4, 0,
    A4, 0,
    G4, 0,
    A4, -3, -1,
    B4, 0,
    A4, 0,
    G4, 0,
    GB4, 0,
    G4, -3, -1,
    G4, 0,
    A4, 0,
    B4, 0,
    G4, 0,
    A4, -3, -1,
    -5,
};

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