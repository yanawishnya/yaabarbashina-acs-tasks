#ifndef __text_cyclic_shift__
#define __text_cyclic_shift__

//------------------------------------------------------------------------------
// text_swap_elements.h - содержит описание текста с шифрованием циклическим сдвигом элементов.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// Текст с шифрованием циклическим сдвигов элементов.
struct text_cyclic_shift {
    // Длина текста.
    int length;
    // Незашифрованный текст.
    char *open_text;
    // Зашифрованный текст.
    char *encrypted_text;
};

// Ввод параметров текста из файла.
void In(text_cyclic_shift &t, ifstream &ifst);

// Ввод случайного текста.
void InRand(text_cyclic_shift &t, int size);

// Вывод параметров текста в форматируемый поток.
void Out(text_cyclic_shift &t, ofstream &ofst);

// Шифрование текста.
void Encrypt(text_cyclic_shift &t);

// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Quotient(text_cyclic_shift &t);

#endif //__text_cyclic_shift__
