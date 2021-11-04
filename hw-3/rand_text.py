import random
import string

from extender import *


# ----------------------------------------
# Функция для получения рандомного текста.
def randomize(number):
    final_str = ""
    counter = -1
    while counter != number:
        final_str += random.randint(1, 3).__str__() + "\n"
        text_length = random.randint(1, 50)
        for i in range(text_length):
            final_str += random.choice(string.ascii_letters)
        if counter != number - 1:
            final_str += "\n"
        counter += 1
    return final_str
