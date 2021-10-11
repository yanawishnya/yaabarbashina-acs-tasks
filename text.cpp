//------------------------------------------------------------------------------
// text.cpp - содержит процедуры связанные с обработкой обобщенного текста
// и создания произвольной шифровки
//------------------------------------------------------------------------------

#include "text.h"

//------------------------------------------------------------------------------
// Ввод обобщенного текста из файла.
text *In(std::ifstream &ifst) {
    text *t;
    int key;
    ifst >> key;
    switch(key) {
        case 1:
            t = new text;
            t->k = text::SWAP;
            In(t->swapElements, ifst);
            return t;
        case 2:
            t = new text;
            t->k = text::SHIFT;
            In(t->cyclicShift, ifst);
            return t;
        case 3:
            t = new text;
            t->k = text::DIGITS;
            In(t->changeWithDigits, ifst);
            return t;
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Ввод случайного текста.
text *InRand() {
    text *txt;
    int key = rand() % 3 + 1;
    int randSize = rand() % 100 + 1;
    switch (key) {
        case 1:
            txt = new text;
            txt->k = text::SWAP;
            InRand(txt->swapElements, randSize);
            return txt;
        case 2:
            txt = new text;
            txt->k = text::SHIFT;
            InRand(txt->cyclicShift, randSize);
            return txt;
        case 3:
            txt = new text;
            txt->k = text::DIGITS;
            InRand(txt->changeWithDigits, randSize);
            return txt;
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Вывод зашифрованного текста в поток.
void Out(text &s, ofstream &ofst) {
    switch(s.k) {
        case text::SWAP:
            Out(s.swapElements, ofst);
            break;
        case text::SHIFT:
            Out(s.cyclicShift, ofst);
            break;
        case text::DIGITS:
            Out(s.changeWithDigits, ofst);
            break;
        default:
            ofst << "Incorrect encryption!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Quotient(text &s) {
    switch(s.k) {
        case text::SWAP:
            return Quotient(s.swapElements);
        case text::SHIFT:
            return Quotient(s.cyclicShift);
        case text::DIGITS:
            return Quotient(s.changeWithDigits);
        default:
            return 0.0;
    }
}
