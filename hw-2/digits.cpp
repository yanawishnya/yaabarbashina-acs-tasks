//------------------------------------------------------------------------------
// digits.cpp - содержит функции обработки текста с шифровкой заменой символов на числа.
//------------------------------------------------------------------------------

#include "digits.h"

//------------------------------------------------------------------------------
// Ввод текста их потока.
void Digits::In(ifstream &ifst) {
    std::string local;
    ifst >> local;
    char *result = new char[local.length() + 1];
    memcpy(result, local.c_str(), local.length() + 1);
    open_text = result;
    length = local.length();
}

//------------------------------------------------------------------------------
// Ввод случайного незашифрованного текста.
void Digits::InRnd() {
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
void Digits::Out(ofstream &ofst) {
    Encrypt();
    std::string buff;
    for (int i = 0; i < length; ++i) {
        buff += std::to_string(encrypted_text[i]);
    }
    ofst << "It is encryption by replacing characters with numbers:\n" << buff << "\n"
         << "The quotient of dividing the sum of codes of an unencrypted string "
            "by the number of characters in this string: " << Quotient() <<"\n";
}

//------------------------------------------------------------------------------
// Шифрование текста.
void Digits::Encrypt() {
    encrypted_text = new int[length];
    for (int i = 0; i < length; ++i) {
        encrypted_text[i] = static_cast<short>(open_text[i]);
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Digits::Quotient() {
    double code = 0;
    for (int i = 0; i < length; ++i) {
        code += open_text[i];
    }
    double answer = code / length;
    return answer;
}
