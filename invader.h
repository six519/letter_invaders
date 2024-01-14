#ifndef _INVADER_H_
#define _INVADER_H_

#define AVAILABLE_LETTERS_COUNT 27
#define LETTER_MAX_LENGTH 10

static char AVAILABLE_LETTERS[AVAILABLE_LETTERS_COUNT][LETTER_MAX_LENGTH] = {
    "a",
    "b",
    "c",
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
        Invader(int x, int letterIndex);
        int x;
        int y;
        int letterIndex;
        int isVisible;
};

#endif