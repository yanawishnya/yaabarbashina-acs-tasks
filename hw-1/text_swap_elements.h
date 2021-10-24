#ifndef __text_swap_elements__
#define __text_swap_elements__

//------------------------------------------------------------------------------
// text_swap_elements.h - содержит описание текста с шифрованием замены элементов на другие элементы.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

// Текст с шифрованием замены элементов на другие элементы.
struct text_swap_elements {
    // Длина текста.
    int length;
    // Незашифрованный текст.
    char *open_text;
    // Зашифрованный текст.
    char *encrypted_text;
};

// Ввод параметров текста из файла.
void In(text_swap_elements &t, ifstream &ifst);

// Ввод случайного текста.
void InRand(text_swap_elements &t, int size);

// Вывод параметров текста в форматируемый поток.
void Out(text_swap_elements &t, ofstream &ofst);

// Шифрование текста.
void Encrypt(text_swap_elements &t);

// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Quotient(text_swap_elements &t);

#endif //__text_swap_elements__
