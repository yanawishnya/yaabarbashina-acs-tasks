#ifndef __text_change_with_digits__
#define __text_change_with_digits__

//------------------------------------------------------------------------------
// text_swap_elements.h - содержит описание текста, зашифрованного заменой элементов на числа.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// Текст с шифрованием заменой элементов на числа.
struct text_change_with_digits {
    int length;
    char *open_text;
    int *encrypted_text;
};

// Ввод параметров текста из файла.
void In(text_change_with_digits &t, ifstream &ifst);

// Ввод случайного текста.
void InRand(text_change_with_digits &t, int size);

// Вывод параметров текста в форматируемый поток.
void Out(text_change_with_digits &t, ofstream &ofst);

// Шифрование текста.
void Encrypt(text_change_with_digits &t);

// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Quotient(text_change_with_digits &t);

#endif //__text_change_with_digits__
