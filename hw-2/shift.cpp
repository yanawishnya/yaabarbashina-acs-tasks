//------------------------------------------------------------------------------
// shift.cpp - содержит функции обработки текста с шифрованием циклическим сдвигом.
//------------------------------------------------------------------------------

#include "shift.h"
//------------------------------------------------------------------------------
// Ввод текста из потока.
void Shift::In(ifstream &ifst) {
    std::string local;
    ifst >> local;
    char *result = new char[local.length() + 1];
    memcpy(result, local.c_str(), local.length() + 1);
    open_text = result;
    length = local.length();
}

//------------------------------------------------------------------------------
// Ввод случайного незашифрованного текста.
void Shift::InRnd() {
    int size = Text::rnd26.Get();
    std::string local;
    open_text = new char[size];
    for (int i = 0; i < size; ++i) {
        int randomNumber = rand() % 26;
        char randomLetter = 'a' + randomNumber;
        open_text[i] = randomLetter;
        local += randomLetter;
    }
    length = local.length();
}

//------------------------------------------------------------------------------
// Вывод зашифрованного текста в поток.
void Shift::Out(ofstream &ofst) {
    Encrypt();
    ofst << "It is encryption by cyclic shifting the code of each symbol by n:\n"
         << encrypted_text << "\n" << "The quotient of dividing the sum of codes of an unencrypted string "
                                        "by the number of characters in this string: " << Quotient() <<"\n";
}

//------------------------------------------------------------------------------
// Шифрование текста.
void Shift::Encrypt() {
    int shift = 3;
    encrypted_text = new char[length];
    for (int i = 0; i < length; ++i)
    {
        char c = open_text[i];
        if (c >= 'A' && c <= 'Z') {
            c = (((c - 'A') + shift) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            c = (((c - 'a') + shift) % 26) + 'a';
        } else if (c >= '0' && c <= '9') {
            c = (((c - '0') + shift) % 10) + '0';
        }
        encrypted_text[i] = c;
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Shift::Quotient() {
    double code = 0;
    for (int i = 0; i < length; ++i) {
        code += open_text[i];
    }
    double answer = code / length;
    return answer;
}
