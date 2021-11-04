from text import *


# ----------------------------------------------------------------------------
# swap.cpp - содержит функции обработки текста с шифрованием заменой символов.
class Swap(Text):
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
        out_stream.write("Text with swap encryption: \n\tOpen text: {} \n\tEncrypted text = {}"
                         "\n\tQuotient = {}".format(self.open_text, self.encrypted_text, self.quotient()))
        pass

    # Шифровка текста.
    def encrypt(self):
        cipher = 'c12defg3klm5ns4tu67vwx8opq0ry9zabhij'
        self.length = len(self.open_text)
        for i in range(self.length):
            while i >= len(cipher):
                i = i - len(cipher)
            self.encrypted_text += cipher[i]
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
