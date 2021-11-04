from text import *


# -------------------------------------------------------------------------------
# shift.py - содержит функции обработки текста с шифрованием циклическим сдвигом.
class Shift(Text):
    # Инициализация текста.
    def __init__(self):
        self.open_text = ""
        self.encrypted_text = ""
        self.length = 0

    # Ввод текста.
    def read_array(self, str_array, i):
        if i >= len(str_array):
            return 0
        self.open_text = str_array[i]
        i += 1
        return i

    # Вывод текста в файл.
    def write(self, out_stream):
        self.encrypt()
        out_stream.write("Text with shift encryption: \n\tOpen text: {} \n\tEncrypted text = {}"
                         "\n\tQuotient = {}".format(self.open_text, self.encrypted_text, self.quotient()))
        pass

    # Шифровка текста.
    def encrypt(self):
        shift = 3
        self.length = len(self.open_text)
        for i in range(self.length):
            c = self.open_text[i]
            if 'A' <= c <= 'Z':
                c = chr((((ord(c) - ord('A')) + shift) % 26) + ord('A'))
            elif 'a' <= c <= 'z':
                c = chr((((ord(c) - ord('a')) + shift) % 26) + ord('a'))
            elif '0' <= c <= '9':
                c = chr((((ord(c) - ord('0')) + shift) % 26) + ord('0'))
            self.encrypted_text += c
        pass

    # Нахождение частного.
    def quotient(self):
        code_sum = 0
        for i in range(len(self.open_text)):
            code_sum += ord(self.open_text[i])
        return code_sum / len(self.open_text)
        pass

    # Переопределение операции > для текста.
    def __gt__(self, other):
        return self.quotient() > other.quotient()
