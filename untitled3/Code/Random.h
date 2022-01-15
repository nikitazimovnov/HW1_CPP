
#ifndef __Random__
#define __Random__

#include <cstdlib>
#include <iostream>
using namespace std;

inline string Random_text(){
    int length = rand() % 100 + 10;
    string text = "";
    int flag;
    for (int i = 0; i < length; ++i) {
        flag = rand();
        text += (rand() % ('a' - 'z' + 1)) + 'a';
        if (flag % 20 == 1){
            text += '.';
        }
        else if (flag % 20 == 2){
            text += ',';
        }
        else if (flag % 20 == 3){
            text += '-';
        }
    }
    return text;
}

inline string Random_special(){
    int length = rand() % 10 + 5;
    string  special = "";

    for (int i = 0; i < length; ++i) {
        special += (rand() % ('a' - 'z' + 1)) + 'a';
    }

    return special;
}

inline int Random() {
    return abs(rand() % 1000) + 3;
}

#endif
