//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "container.h"

// Обработка ошибки и неверной вводной строке.
void errorMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command file inputFile outputFile1 outputFile2\n"
            "      or\n"
            "     command random number outputFile1 outputFile2" << "\n";
}

// Ошибка о некорректном количестве текстов для рандомного заполнения.
void errorMessage2() {
    cout << "Incorrect number of texts. Set number less than 10000." << "\n";
}

// Ошибка о неправильном квалификаторе (не file/random).
void errorMessage3() {
    cout << "Qualifier is not file or random. Should be one of the above. Try again." << "\n";
}

//------------------------------------------------------------------------------
// Точка запуска программы.
int main(int argc, char *argv[]) {
    if (argc != 5) {
        errorMessage1();
        return 1;
    }
    cout << "Start"<< endl;
    Container c;

    if (!strcmp(argv[1], "file")) {
        ifstream ifst(argv[2]);
        c.In(ifst);
    } else if (!strcmp(argv[1], "random")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            errorMessage2();
            return 2;
        }
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    } else {
        errorMessage3();
        return 3;
    }

    // Вывод содержимого контейнера в первый файл для вывода.
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.Out(ofst1);

    // Вывод отсортированного содержимого контейнера во второй файл для вывода.
    ofstream ofst2(argv[4]);
    c.BubbleSort();
    ofst2 << "Sorted container:\n";
    c.Out(ofst2);
    c.Clear();
    cout << "End"<< endl;
    return 0;
}
