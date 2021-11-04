import sys

from extender import *

# ------------------------
# Точка запуска программы.
if __name__ == '__main__':
    # Количество аргументов при запуске должно равняться 5.
    if len(sys.argv) == 5:
        # Считывается квалифайер, он должен быть либо file, либо random.
        qualifier = sys.argv[1]
        if qualifier == "file":
            input_file_name = sys.argv[2]
            output_file_name = sys.argv[3]
            output_file_name_sorted = sys.argv[4]
        elif qualifier == "random":
            rand_num = int(sys.argv[2])
            output_file_name = sys.argv[3]
            output_file_name_sorted = sys.argv[4]
        else:
            print("Incorrect qualifier. Must be file or random.")
            exit()
    else:
        print("Incorrect command line! You must write: \n\tpython main file <inputFileName> <outputFileName> "
              "<outputFileNameSorted> \n\tor\n\tpython main random <number> <outputFileName> <outputFileNameSorted>")
        exit()

    if qualifier == "file":
        in_file = open(input_file_name)
        read_str = in_file.read()
        in_file.close()
        strArray = read_str.replace("\n", " ").split(" ")
    elif qualifier == "random":
        strArray = randomize(rand_num)
        strArray = strArray.replace("\n", " ").split(" ")

    # Начало обработки вводных данных.
    print('==> Start')

    container = Container()
    figNum = read_array(container, strArray)

    # Вывод неотсортированного массива текстов после обработки.
    out_file = open(output_file_name, 'w')
    container.write(out_file)
    out_file.close()

    # Вывод отсортированного массива текстов после обработки.
    out_file_sorted = open(output_file_name_sorted, 'w')
    container.bubble_sort()
    container.write(out_file_sorted)
    out_file_sorted.close()

    # Конец.
    print('==> Finish')
    pass
