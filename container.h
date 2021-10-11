#ifndef __container__
#define __container__

#include "text.h"

struct container {
    enum {
        max_len = 10000
    }; // максимальная длина
    int len; // текущая длина
    text *cont[max_len];
};

// Инициализация контейнера.
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока.
void In(container &c, std::ifstream &ifst);

// Случайное наполнение контейнера.
void InRand(container &c, int size);

// Вывод содержимого контейнера в указанный поток.
void Out(container &c, std::ofstream &ofst);

// Сортировка пузырьком.
void BubbleSort(container &c);

#endif
