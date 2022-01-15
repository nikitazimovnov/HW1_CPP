#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "Container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile\n"
            "  Or:\n"
            "     command -n number outfile\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile\n"
            "  Or:\n"
            "     command -n number outfile\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    unsigned int start_time = clock();
    if (argc != 4) {
        errMessage1();
        return 1;
    }

    cout << "Start" << endl;
    Container c{};
    Init(c);

    ////cout << "argv[1] = " << argv[1] << "\n";
    if (!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        In(c, ifst);
    }
    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            cout << "incorrect numer of phrases = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }

        srand(static_cast<unsigned int>(time(nullptr)));
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);

    ofst1 << "\n \n \n" << "Shake-Sorted container: \n";
    ShakeSort(c);
    Out(c, ofst1);

    Clear(c);
    cout << "Stop" << endl;
    unsigned int end_time = clock();
    std::cout << "working time: " << end_time - start_time << " ms\n";
    return 0;
}
