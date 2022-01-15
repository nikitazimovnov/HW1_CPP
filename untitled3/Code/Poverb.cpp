

#include "Poverb.h"
#include <fstream>
using namespace std;

void In(Poverb& pov, ifstream& ifst) {
    ifst >> pov.country_length >> pov.text_length >> pov.signs_count;
}

void InRnd(Poverb& pov) {
    string text = Random_text();
    int signs_count = 0;
    for (char sym : text){
        if (sym == '.' || sym == ',' || sym == '-'){
            signs_count++;
        }
    }
    pov.signs_count = signs_count;
    pov.text_length = text.length();
    pov.country_length = Random_special().length();
}

void Out(Poverb& pov, ofstream& ofst) {
    ofst << "It is poverb \n"
         << "Author's name length: " << pov.country_length << "\n"
         << "text length " << pov.text_length << "\n" << "signs count:" << pov.signs_count << "\n"
         << "main_func = " << main_func(pov) << "\n" << "\n";
}

double main_func(Poverb& pov) {
    return pov.signs_count / (double)(pov.text_length);
}
