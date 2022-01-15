
#include "Container.h"


void Init(Container& c) {
    c.len = 0;
}

void Clear(Container& c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

void In(Container& c, ifstream& ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

void InRnd(Container& c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

void Out(Container& c, ofstream& ofst) {
    ofst << "Container contains " << c.len << " elements." << "\n" << endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i + 1 << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

void ShakeSort(Container& c)
{
    int i, j, k;
    int m = c.len;
    for (i = 0; i < m;) {
        for (j = i + 1; j < m; j++) {
            if (main_func(*c.cont[j]) < main_func(*c.cont[j - 1]))
                swap(c.cont[j], c.cont[j - 1]);
        }
        m--;
        for (k = m - 1; k > i; k--) {
            if (main_func(*c.cont[k]) < main_func(*c.cont[k - 1]))
                swap(c.cont[k], c.cont[k - 1]);
        }
        i++;
    }
}