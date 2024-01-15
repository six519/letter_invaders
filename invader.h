#ifndef _INVADER_H_
#define _INVADER_H_
#include <graphics.h>

#define AVAILABLE_LETTERS_COUNT 76
#define LETTER_MAX_LENGTH 10
#define INVADER_SPEED 1
#define INVADER_DEFAULT_Y 23

static char AVAILABLE_LETTERS[AVAILABLE_LETTERS_COUNT][LETTER_MAX_LENGTH] = {
    "a", "A",
    "b", "B",
    "c", "C",
    "d", "D",
    "e", "E",
    "f", "F",
    "g", "G",
    "h", "H",
    "i", "I",
    "j", "J",
    "k", "K",
    "l", "L",
    "m", "M",
    "n", "N",
    "o", "O",
    "p", "P",
    "q", "Q",
    "r", "R",
    "s", "S",
    "t", "T",
    "u", "U",
    "v", "V",
    "w", "W",
    "x", "X",
    "y", "Y",
    "z", "Z",
    "Ja"
    "sal",
    "lall;",
    "Da",
    "adj",
    "sad;",
    "Dak",
    "Lassas",
    "Salads",
    "all",
    "Adj;",
    "djs;",
    "Asks;",
    "Kas;",
    "Alaska",
    "Falls",
    "daas;",
    "Ala",
    "Fads",
    "Kafka",
    "fl",
    "alds;",  
    "ask",
    "Slask",
};

class Invader 
{
    public:
        Invader(int letterIndex);
        int x;
        int y;
        int letterIndex;
        int isVisible;
        void draw();
};

#endif