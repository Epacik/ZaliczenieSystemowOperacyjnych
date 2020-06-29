#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <errno.h>

extern int errno;

// Funkcja wypisująca wiadomość błędu na podstawie jego kodu
void ErrLog(){
    int errnum = errno;
    printf("Kod błędu: %d", errnum);
    printf((char*)strerror( errnum ));
}

// Funkcja wypisująca wiadomość błędu i czyszcząca errno
void ErrLogAndClear(){
    ErrLog();
    errno = 0;
}

int main(void) {
    setlocale(0, "pl_PL");

    errno = 0;
    //Otwieranie pliku do zapisu i tworzenie go jeśli nie istniał wcześniej
    int fdesc = open("./testowyPlik.txt", O_WRONLY | O_CREAT);
    if (fdesc == -1) {
        ErrLogAndClear();
        return -1;
    }
    puts("Pomyślnie otwarto plik");

#pragma region Zapis do pliku

    char buf[] = "Jakiś tekst do zapisania w pliku\0";
    int size = strlen(buf);

    int res = write(fdesc, buf, size);
    if(res == -1)
    {
        ErrLogAndClear();
        return -1;
    }

#pragma endregion
    
    //zamykanie pliku
    res = close(fdesc);

    //otwieranie pliku do odczytu
    fdesc = open("./testowyPlik.txt", O_RDONLY );

    //Sprawdzanie pozycji w pliku
    int position = lseek(fdesc, 0, SEEK_CUR);
    puts("Obecna pozycja:" );
    printf("%d\n", position);

#pragma region Odczytywanie z pliku

    char* readed = malloc(sizeof(char) * size + 1 );

    res = read(fdesc, readed, size);
    readed[size] = '\0';
    if(res == -1){
        ErrLogAndClear();
        return -1;
    }

#pragma endregion

    puts(readed);

    free(readed);

    //zamykanie pliku
    res = close(fdesc);
    if(res == -1){
        ErrLogAndClear();
        return -1;
    }
    
    return 0;
}
