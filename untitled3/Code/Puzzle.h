
#ifndef __Puzzle__
#define __Puzzle__

#include <fstream>
#include "Random.h"
using namespace std;

struct Puzzle {
    int answer_length;
    int text_length;
    int signs_count;
};

void In(Puzzle& puz, ifstream& ifst);

void InRnd(Puzzle& puz);

void Out(Puzzle& puz, ofstream& ofst);

double main_func(Puzzle& puz);


#endif
