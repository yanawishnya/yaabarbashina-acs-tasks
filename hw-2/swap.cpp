//------------------------------------------------------------------------------
// swap.cpp - содержит функции обработки текста с шифрованием заменой символов.
//------------------------------------------------------------------------------

#include "swap.h"

//------------------------------------------------------------------------------
// Ввод текста из потока.
void Swap::In(ifstream &ifst) {
    std::string local;
    ifst >> local;
    char *result = new char[local.length() + 1];
    memcpy(result, local.c_str(), local.length() + 1);
    open_text = result;
    length = local.length();
}

//------------------------------------------------------------------------------
// Ввод случайного незашифрованного текста.
void Swap::InRnd() {
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
void Swap::Out(ofstream &ofst) {
    Encrypt();
    ofst << "It is encryption by swapping symbols with another symbols:\n"
         << encrypted_text << "\n" << "The quotient of dividing the sum of codes of an unencrypted string "
                                        "by the number of characters in this string: " << Quotient() <<"\n";
}

//------------------------------------------------------------------------------
// Шифрование текста.
void Swap::Encrypt() {
    encrypted_text = new char[length];
    for (int i = 0; i < length; ++i) {
        encrypted_text[i] = 'a' + 'z' - static_cast<int>(open_text[i]);
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Swap::Quotient() {
    double code = 0;
    for (int i = 0; i < length; ++i) {
        code += open_text[i];
    }
    double answer = code / length;
    return answer;
}
