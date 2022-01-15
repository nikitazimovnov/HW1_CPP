

#include "Aphorism.h"
#include <fstream>
using namespace std;

void In(Aphorism& aph, ifstream& ifst) {
    ifst >> aph.name_length >> aph.text_length >> aph.signs_count;
}

void InRnd(Aphorism& aph) {
    string text = Random_text();
    int signs_count = 0;
    for (char sym : text){
        if (sym == '.' || sym == ',' || sym == '-'){
            signs_count++;
        }
    }
    aph.signs_count = signs_count;
    aph.text_length = text.length();
    aph.name_length = Random_special().length();
}

void Out(Aphorism& aph, ofstream& ofst) {
    ofst << "It is aphorism \n"
         << "Author's name length: " << aph.name_length << "\n"
         << "text length " << aph.text_length << "\n" << "signs count:" << aph.signs_count << "\n"
         << "main_func = " << main_func(aph) << "\n" << "\n";
}

double main_func(Aphorism& aph) {
    return aph.signs_count / (double)(aph.text_length);
}
