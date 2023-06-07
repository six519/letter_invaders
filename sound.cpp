#include "sound.h"

Sound::Sound(int notes[], int isLoop, int nCount)
{
    isPlaying = 0;
    isLooping = isLoop;
    noteCount = nCount;

    for (int x; x < noteCount; x++)
    {
        notesList[x] = notes[x];
    }
}

void Sound::play()
{

}

void Sound::process()
{

}

void Sound::stop()
{

}