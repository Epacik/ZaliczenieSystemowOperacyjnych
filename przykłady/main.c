#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    set_locale(0, "pl_PL");

    //Otwieranie pliku
    int fdesc = open("testowyPlik.txt", O_WRONLY | O_APPEND);
    if (fdesc == -1) {
        puts("Błąd odczytu pliku");
        return 1;
    }
    puts("Pomyślnie otwarto plik");

    //Zapis do pliku
    char buf[] = "Jakiś tekst do zapisania w pliku\0";
    int size = strlen(buf);

    int res = write(fdesc, buf, strlen(buf));
    if(res == -1)
    {
        puts("Wystąpił błąd zapisu do pliku");
        return 1;
    }

    //Sprawdzanie pozycji w pliku
    int position = lseek(fdesc, size, SEEK_CUR);
    puts("Obecna pozycja: " );
    puts(position);

    //Odczytywanie z pliku
    char* readed = malloc(sizeof(char) * size);

    res = read(fdesc, readed, size);


    free(readed);
    return 0;
}
