
#ifndef __Poverb__
#define __Poverb__

#include <fstream>
#include "Random.h"
using namespace std;

struct Poverb {
    int country_length;
    int text_length;
    int signs_count;
};

void In(Poverb& pov, ifstream& ifst);

void InRnd(Poverb& pov);

void Out(Poverb& pov, ofstream& ofst);

double main_func(Poverb& pov);


#endif