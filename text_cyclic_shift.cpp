//------------------------------------------------------------------------------
// text_cyclic_shift.cpp - содержит функции обработки текста.
//------------------------------------------------------------------------------

#include "text_cyclic_shift.h"
#include "string.h"

//------------------------------------------------------------------------------
// Ввод текста из потока.
void In(text_cyclic_shift &t, ifstream &ifst) {
    std::string local;
    ifst >> local;
    char *result = new char[local.length() + 1];
    memcpy(result, local.c_str(), local.length() + 1);
    t.open_text = result;
    t.length = local.length();
}

//------------------------------------------------------------------------------
// Ввод случайного незашифрованного текста.
void InRand(text_cyclic_shift &t, int size) {
    std::string local = "";
    t.open_text = new char[size];
    for (int i = 0; i < size; ++i) {
        int randomNumber = rand() % 26;
        char randomLetter = 'a' + randomNumber;
        t.open_text[i] = randomLetter;
        local += randomLetter;
    }
    t.length = local.length();
}

//------------------------------------------------------------------------------
// Вывод зашифрованного текста в поток.
void Out(text_cyclic_shift &t, ofstream &ofst) {
    Encrypt(t);
    ofst << "It is encryption by cyclic shifting the code of each symbol by n:\n"
         << t.encrypted_text << "\n" << "The quotient of dividing the sum of codes of an unencrypted string "
                                        "by the number of characters in this string: " << Quotient(t) <<"\n";
}

//------------------------------------------------------------------------------
// Шифрование текста.
void Encrypt(text_cyclic_shift &t) {
    int shift = 3;
    t.encrypted_text = new char[t.length];
    for (int i = 0; i < t.length; ++i)
    {
        char c = t.open_text[i];
        if (c >= 'A' && c <= 'Z') {
            c = (((c - 'A') + shift) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            c = (((c - 'a') + shift) % 26) + 'a';
        } else if (c >= '0' && c <= '9') {
            c = (((c - '0') + shift) % 10) + '0';
        }
        t.encrypted_text[i] = c;
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Quotient(text_cyclic_shift &t) {
    double code = 0;
    for (int i = 0; i < t.length; ++i) {
        code += t.open_text[i];
    }
    double answer = code / t.length;
    return answer;
}


