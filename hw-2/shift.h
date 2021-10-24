#ifndef __shift__
#define __shift__

//------------------------------------------------------------------------------
// shift.h - содержит описание текста с шифрованием циклическим сдвигом элементов.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "text.h"

//------------------------------------------------------------------------------
// треугольник
class Shift: public Text {
public:
    virtual ~Shift() {}
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

#endif //__shift__
