#ifndef __font__
#define __font__

//------------------------------------------------------------------------------
// text.h - содержит описание обобщающего зашифрованного текста
//------------------------------------------------------------------------------

#include "text_change_with_digits.h"
#include "text_swap_elements.h"
#include "text_cyclic_shift.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся тексты
struct text {
// значения ключей для каждого из шифровок.
    enum key {
        SWAP, SHIFT, DIGITS
    };
    key k; // ключ
    // используемые альтернативы
    union {
        text_swap_elements swapElements;
        text_cyclic_shift cyclicShift;
        text_change_with_digits changeWithDigits;
    };
};

// Ввод обобщенной шифровки текста.
text *In(std::ifstream &ifst);

// ВВод случайного текста.
text *InRand();

// Вывод обобщенной шифровки текста.
void Out(text &s, std::ofstream &ofst);

// Вычисление частного от деления суммы кодов незашифрованной строки на число символов в этой строке.
double Quotient(text &s);

#endif
