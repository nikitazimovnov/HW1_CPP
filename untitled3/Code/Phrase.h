#ifndef __Phrase__
#define  __Phrase__

#include "Aphorism.h"
#include "Poverb.h"
#include "Puzzle.h"
#include <fstream>


struct Phrase {
    enum Key { APHORISM = 1, POVERB = 2, PUZZLE = 3 };

    Key k;

    Phrase() {

    };

    ~Phrase() {

    };

    union {
        Aphorism aph;
        Poverb pov;
        Puzzle puz;
    };
};

Phrase* In(std::ifstream& ifst);

Phrase* InRnd();

void Out(Phrase& phrase, std::ofstream& ofst);

double main_func(Phrase& phrase);

#endif