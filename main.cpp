#include "iostream"
#include "string.h"

#include "container.h"

void errorMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command file inputFile outputFile1 outputFile2\n"
            "      or\n"
            "     command random number outputFile1 outputFile2" << "\n";
}

void errorMessage2() {
    cout << "Incorrect number of texts. Set number less than 10000." << "\n";
}

void errorMessage3() {
    cout << "Qualifier is not file or random. Should be one of the above. Try again." << "\n";
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        errorMessage1();
        return 1;
    }

    container c{};
    Init(c);
    if (!strcmp(argv[1], "file")) {
        ifstream ifst(argv[2]);
        In(c, ifst);
    } else if (!strcmp(argv[1], "random")) {
        auto size = stoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            errorMessage2();
            return 2;
        }
        // Заполнение контейнера генератором случайных чисел.
        InRand(c, size);
    } else {
        errorMessage3();
        return 3;
    }
    ofstream ofst1(argv[3]);
    ofstream ofst2(argv[4]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);

    BubbleSort(c);
    ofst2 << "Sorted container:\n";
    Out(c, ofst2);
    Clear(c);
    cout << "Happy end."<< endl;
    return 0;
}
