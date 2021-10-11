//------------------------------------------------------------------------------
// text_swap_elements.cpp - содержит функции обработки текста.
//------------------------------------------------------------------------------

#include "text_swap_elements.h"
#include "string.h"

//------------------------------------------------------------------------------
// Ввод текста из потока.
void In(text_swap_elements &t, ifstream &ifst) {
    std::string local;
    ifst >> local;
    char *result = new char[local.length() + 1];
    memcpy(result, local.c_str(), local.length() + 1);
    t.open_text = result;
    t.length = local.length();
}

//------------------------------------------------------------------------------
// Ввод случайного незашифрованного текста.
void InRand(text_swap_elements &t, int size) {
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
void Out(text_swap_elements &t, ofstream &ofst) {
    Encrypt(t);
    ofst << "It is encryption by swapping symbols with another symbols:\n"
         << t.encrypted_text << "\n" << "The quotient of dividing the sum of codes of an unencrypted string "
                                        "by the number of characters in this string: " << Quotient(t) <<"\n";
}

//------------------------------------------------------------------------------
// Шифрование текста.
void Encrypt(text_swap_elements &t) {
    t.encrypted_text = new char[t.length];
    for (int i = 0; i < t.length; ++i) {
        t.encrypted_text[i] = 'a' + 'z' - static_cast<int>(t.open_text[i]);
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Quotient(text_swap_elements &t) {
    double code = 0;
    for (int i = 0; i < t.length; ++i) {
        code += t.open_text[i];
    }
    double answer = code / t.length;
    return answer;
}


