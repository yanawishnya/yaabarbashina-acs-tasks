from extender import *
from swap import Swap


# --------------------------------------------------------------
# read_array.py - считывание типов шифровок и текстов из строки.
def read_array(container, str_array):
    array_len = len(str_array)
    i = 0
    text_num = 0
    while i < array_len:
        temp = str_array[i]
        key = int(temp)
        if key == 1:
            i += 1
            text = Swap()
            i = text.read_array(str_array, i)
        elif key == 2:
            i += 1
            text = Shift()
            i = text.read_array(str_array, i)
        elif key == 3:
            i += 1
            text = Digits()
            i = text.read_array(str_array, i)
        else:
            return text_num
        if i == 0:
            return text_num
        text_num += 1
        container.store.append(text)
    return text_num
