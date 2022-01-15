

#include "Puzzle.h"
#include <fstream>
using namespace std;

void In(Puzzle& puz, ifstream& ifst) {
    string inter;
    ifst >> puz.answer_length >> puz.text_length >> puz.signs_count >> inter;
}

void InRnd(Puzzle& puz) {
    string text = Random_text();
    int signs_count = 0;
    for (char sym : text){
        if (sym == '.' || sym == ',' || sym == '-'){
            signs_count++;
        }
    }
    puz.signs_count = signs_count;
    puz.text_length = text.length();
    puz.answer_length = Random_special().length();
}

void Out(Puzzle& puz, ofstream& ofst) {
    ofst << "It is puzzle \n"
         << "Author's name length: " << puz.answer_length << "\n"
         << "text length " << puz.text_length << "\n" << "signs count:" << puz.signs_count << "\n"
         << "main_func = " << main_func(puz) << "\n" << "\n";
}

double main_func(Puzzle& puz) {
    return puz.signs_count / (double)(puz.text_length);
}