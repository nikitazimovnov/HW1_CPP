
#include "Phrase.h"
#include <fstream>

Phrase* In(std::ifstream& ifst){
    Phrase* phrase;
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            phrase = new Phrase;
            phrase->k = Phrase::APHORISM;
            In(phrase->aph, ifst);
            return phrase;
        case 2:
            phrase = new Phrase;
            phrase->k = Phrase::POVERB;
            In(phrase->pov, ifst);
            return phrase;
        case 3:
            phrase = new Phrase;
            phrase->k = Phrase::PUZZLE;
            In(phrase->puz, ifst);
            return phrase;
        default:
            return 0;
    }
}

Phrase* InRnd() {
    Phrase* ph;
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            ph = new Phrase;
            ph->k = Phrase::APHORISM;
            InRnd(ph->aph);
            return ph;
        case 2:
            ph = new Phrase;
            ph->k = Phrase::POVERB;
            InRnd(ph->pov);
            return ph;
        case 3:
            ph = new Phrase;
            ph->k = Phrase::PUZZLE;
            InRnd(ph->puz);
            return ph;
        default:
            return 0;
    }
}

void Out(Phrase& ph, ofstream& ofst) {
    switch (ph.k) {
        case Phrase::APHORISM:
            Out(ph.aph, ofst);
            break;
        case Phrase::POVERB:
            Out(ph.pov, ofst);
            break;
        case Phrase::PUZZLE:
            Out(ph.puz, ofst);
            break;
        default:
            ofst << "Incorrect phrase." << endl;
    }
}

double main_func(Phrase& ph) {
    switch (ph.k) {
        case Phrase::APHORISM:
            return main_func(ph.aph);
        case Phrase::POVERB:
            return main_func(ph.pov);
        case Phrase::PUZZLE:
            return main_func(ph.puz);
        default:
            return 0.0;
    }
}
