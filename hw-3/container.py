import swap
import shift
import digits


# ----------------------------------------------
# Класс контейнера для хранения текстов с разными типами шифровок.
class Container:
    # Конструктор.
    def __init__(self):
        self.store = []

    # Вывод содержимого контейра в файл.
    def write(self, out_stream):
        out_stream.write("Container stores {} texts:\n".format(len(self.store)))
        for text in self.store:
            text.write(out_stream)
            out_stream.write("\n")
        out_stream.write("Summa of Quotients  = {}\n".format(self.quotient()))
        pass

    # Подсчёт суммы частных от деления суммы кодов незашифрованной строки на количество элементов в этой строке.
    def quotient(self):
        quotient = 0.0
        for text in self.store:
            quotient += text.quotient()
        return quotient
        pass

    # Сортировка пузырьком.
    def bubble_sort(self):
        n = len(self.store)
        for i in range(n - 1):
            for j in range(0, n - i - 1):
                if self.store[j] < self.store[j + 1]:
                    self.store[j], self.store[j + 1] = self.store[j + 1], self.store[j]
        pass
