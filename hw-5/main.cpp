#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int dataBase[100]{0};
sem_t availableForReaders;
sem_t availableForAuthor;
pthread_mutex_t editedByAuthor;
int authorCount;
int readersCount;
int limit = 50;

void *read(void *args) {
    int readerIndex = *((int *) args);
    // Пока читатели не дочитали записей до лимита, они читают.
    while (readersCount < limit) {
        // Читатель ожидает подтверждения, что никакой писатель сейчас не редактирует записи, и он может читать.
        sem_wait(&availableForReaders);
        int number = rand() % 100;
        // Читает рандомную запись из базы.
        int a = dataBase[number];
        readersCount++;
        std::cout << readerIndex << " reader has read recording with number " << number << "\n";
        // Отправляет подтверждение, что запись прочитана, и писатель может редактировать.
        sem_post(&availableForAuthor);
        // И ещё засыпает.
        sleep(1);
    }
    return nullptr;
}

void *write(void *args) {
    int writerIndex = *((int *) args);
    // Пока писатели не доредактировали записи до лимита, они редактируют.
    while (authorCount < limit) {
        // Ожидают подтверждения, что можно редактировать.
        sem_wait(&availableForAuthor);
        // Поток писателя лочится, так как в одно время только 1 писатель может редактировать БД.
        pthread_mutex_lock(&editedByAuthor);
        int number = rand() % 100;
        // Редактирует запись из БД.
        dataBase[number] = rand() % 100;
        authorCount++;
        // Открывает доступ к БД остальным.
        pthread_mutex_unlock(&editedByAuthor);
        std::cout << writerIndex << " author changed the recording with number " << number << "\n";
        // Разрешает всем читателям пользоваться БД.
        sem_post_multiple(&availableForReaders, 3);
        // И засыпает.
        sleep(2);
    }
    return nullptr;
}

void initializeDB() {
    for (int i = 0; i < 100; ++i) {
        dataBase[i] = i;
    }
}

int main() {
    initializeDB();
    
    //Пользовательский ввод количества читателей.
    std::cout << "Please type in the number of readers." << "\n";
    bool correct = false;
    int readersInput;
    while (!correct) {
        std::cin >> readersInput;
        if (readersInput <= 0) {
            std::cout << "The number of readers should be positive. Try again." << "\n";
        } else {
            correct = true;
        }
    }

    // Пользовательский ввод количества писателей.
    std::cout << "Please type in the number of authors." << "\n";
    correct = false;
    int authorsInput;
    while (!correct) {
        std::cin >> authorsInput;
        if (authorsInput <= 0) {
            std::cout << "The number of authors should be positive. Try again." << "\n";
        } else {
            correct = true;
        }
    }

    // Инициализация мьютекса.
    pthread_mutex_init(&editedByAuthor, nullptr);
    // Инициализация семафора для читателей.
    sem_init(&availableForReaders, 0, readersInput);
    // Инициализация семафора для писателей.
    sem_init(&availableForAuthor, 0, 1);
    authorCount = 0;
    readersCount = 0;

    // Запуск потоков читателей.
    pthread_t readersT[readersInput];
    int readers[readersInput];
    for (int i = 0; i < readersInput; ++i) {
        readers[i] = i + 1;
        pthread_create(&readersT[i], nullptr, read, (void *) (readers + i));
    }

    // Запуск потоков писателей.
    pthread_t authorsT[authorsInput];
    int authors[authorsInput];
    for (int i = 0; i < authorsInput; ++i) {
        authors[i] = i + 1;
        pthread_create(&authorsT[i], nullptr, write, (void *) (authors + i));
    }

    // Главный поток писателя.
    int mainThreadNumber = 0;
    write((void *) &mainThreadNumber);

    // Вывод общей статистики.
    std::cout << "Readers has read " << readersCount << " recordings. Writers has changed " << authorCount
              << " recordings." << "\n";
    return 0;
}
