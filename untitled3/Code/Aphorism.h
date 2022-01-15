
#ifndef __Aphorism__
#define __Aphorism__

#include <fstream>
#include "Random.h"
using namespace std;

struct Aphorism {
    int name_length;
    int text_length;
    int signs_count;
};

void In(Aphorism& aph, ifstream& ifst);

void InRnd(Aphorism& aph);

void Out(Aphorism& aph, ofstream& ofst);

double main_func(Aphorism& aph);


#endif
