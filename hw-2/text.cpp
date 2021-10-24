//------------------------------------------------------------------------------
// text.cpp - содержит процедуры связанные с обработкой обобщенного текста
// и создания произвольной шифровки
//------------------------------------------------------------------------------

#include "digits.h"
#include "swap.h"
#include "shift.h"

Random Text::rnd26(1, 26);
Random Text::rnd3(1,3);

//------------------------------------------------------------------------------
// Ввод обобщенного текста из файла.
Text* Text::StaticIn(ifstream &ifst) {
    int k;
    ifst >> k;
    Text *txt;
    switch(k) {
        case 1:
            txt = new Swap;
            break;
        case 2:
            txt = new Shift;
            break;
        case 3:
            txt = new Digits;
            break;
        default:
            txt = nullptr;
            break;
    }
    txt->In(ifst);
    return txt;
}

//------------------------------------------------------------------------------
// Ввод случайного текста.
Text *Text::StaticInRnd() {
    auto k = Text::rnd3.Get();
    Text *txt;
    switch(k) {
        case 1:
            txt = new Swap;
            break;
        case 2:
            txt = new Shift;
            break;
        case 3:
            txt = new Digits;
            break;
        default:
            txt = nullptr;
            break;
    }
    txt->InRnd();
    return txt;
}


