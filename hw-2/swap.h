#ifndef __swap__
#define __swap__

//------------------------------------------------------------------------------
// swap.h - содержит описание текста с шифрованием замены элементов на другие элементы.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "text.h"

//------------------------------------------------------------------------------
// треугольник
class Swap: public Text {
public:
    virtual ~Swap() {}
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
    char *encrypted_text;
};

#endif //__swap__
