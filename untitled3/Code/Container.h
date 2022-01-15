#ifndef __container__
#define __container__

#include "Phrase.h"

struct Container {
    enum { max_len = 10000 };
    int len;
    Phrase* cont[max_len];
};
void Init(Container& c);

void Clear(Container& c);

void In(Container& c, ifstream& ifst);

void InRnd(Container& c, int size);

void Out(Container& c, ofstream& ofst);

void ShakeSort(Container& c);

#endif
