#include "sound.h"

Sound::Sound(int notes[], int isLoop, int nCount)
{
    isPlay = 0;
    isLooping = isLoop;
    noteCount = nCount;
    currentNote = 0;
    timer = 0;

    for (int x=0; x < noteCount; x++)
    {
        notesList[x] = notes[x];
    }
}

void Sound::play()
{
    currentNote = 0;
    timer = 0;
    isPlay = 1;
}

void Sound::nextNote()
{
    if (currentNote == (noteCount - 1))
    {
        if (!isLooping)
            stop();

        currentNote = 0;
        return;
    }
    currentNote++;
}

void Sound::process()
{

    if (isPlay)
    {
        if (notesList[currentNote] > 0)
        {
            sound(notesList[currentNote]);
            nextNote();
        }
        else
        {
            if (abs(notesList[currentNote]) == timer)
            {
                nextNote();
                timer = 0;
                nosound();
                return;
            }

            timer++;
        }
    }
}

void Sound::stop()
{
    nosound();
    isPlay = 0;
}

int Sound::isPlaying()
{
    return isPlay;
}