#ifndef _INVADER_H_
#define _INVADER_H_
#include <graphics.h>
#include "building.h"

#define AVAILABLE_LETTERS_COUNT 85
#define LETTER_MAX_LENGTH 10
#define INVADER_SPEED 10
#define INVADER_DEFAULT_Y 23
#define INVADER_MOVE_TRIGGER 3

struct Letter {
    char chars[LETTER_MAX_LENGTH];
    int length;
};

static struct Letter AVAILABLE_LETTERS[AVAILABLE_LETTERS_COUNT] = {
    { "a", 1 }, { "A", 1 },
    { "b", 1 }, { "B", 1 },
    { "c", 1 }, { "C", 1 },
    { "d", 1 }, { "D", 1 },
    { "e", 1 }, { "E", 1 },
    { "f", 1 }, { "F", 1 },
    { "g", 1 }, { "G", 1 },
    { "h", 1 }, { "H", 1 },
    { "i", 1 }, { "I", 1 },
    { "j", 1 }, { "J", 1 },
    { "k", 1 }, { "K", 1 },
    { "l", 1 }, { "L", 1 },
    { "m", 1 }, { "M", 1 },
    { "n", 1 }, { "N", 1 },
    { "o", 1 }, { "O", 1 },
    { "p", 1 }, { "P", 1 },
    { "q", 1 }, { "Q", 1 },
    { "r", 1 }, { "R", 1 },
    { "s", 1 }, { "S", 1 },
    { "t", 1 }, { "T", 1 },
    { "u", 1 }, { "U", 1 },
    { "v", 1 }, { "V", 1 },
    { "w", 1 }, { "W", 1 },
    { "x", 1 }, { "X", 1 },
    { "y", 1 }, { "Y", 1 },
    { "z", 1 }, { "Z", 1 },
    { "Ja", 2 },
    { "sal", 3 },
    { "lall;", 5 },
    { "Da", 2 },
    { "adj", 3 },
    { "sad;", 4 },
    { "Dak", 3 },
    { "Lassas", 6 },
    { "Salads", 6 },
    { "all", 3 },
    { "Adj;", 4 },
    { "djs;", 4 },
    { "Asks;", 5 },
    { "Kas;", 4 },
    { "Alaska", 6 },
    { "Falls", 5 },
    { "Falla", 5 },
    { "Fala", 4},
    { "daas;", 5 },
    { "Ala", 3 },
    { "Fads", 4 },
    { "Kafka", 5 },
    { "fl", 2 },
    { "alds;", 5 },  
    { "ask", 3 },
    { "Slask", 5 },
    { "Ada", 3 },
    { "Jas", 3 },
    { "La", 2 },
    { "akkad", 5 },
    { "Jaffa", 5 },
    { "Dada", 4 },
    { "Add", 3 },
};

class Invader 
{
    private:
        int canMove();
        int moveTime;
    public:
        Invader(int letterIndex);
        int x;
        int y;
        int letterIndex;
        int isVisible;
        int selectedCount;
        void draw();
};

#endif