#ifndef __digits__
#define __digits__

//------------------------------------------------------------------------------
// digits.h - содержит описание текста, зашифрованного заменой элементов на числа.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "text.h"

//------------------------------------------------------------------------------
// Текст с шифрованием заменой элементов на числа.
class Digits: public Text {
public:
    virtual ~Digits() {}
    // Ввод параметров текста из файла.
    virtual void In(ifstream &ifst);
    // Ввод случайного текста.
    virtual void InRnd();
    // Вывод параметров текста в форматируемый поток.
    virtual void Out(ofstream &ofst);
    // Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
    virtual double Quotient();
    // Шифрование текста.
    virtual void Encrypt();
private:
    int length;
    char *open_text;
    int *encrypted_text;
};

#endif //__digits__
