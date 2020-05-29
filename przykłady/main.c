#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    set_locale(0, "pl_PL");

    int fdesc = open("testowyPlik.txt", O_WRONLY | O_APPEND);
    if (fdesc == -1) {
        puts("Błąd odczytu pliku");
        return 1;
    }
    puts("Pomyślnie otwarto plik");

    char buf[] = "Jakiś tekst do zapisania w pliku\0";
    int size = strlen(buf);

    int res = write(fdesc, buf, strlen(buf));
    if(res == -1)
    {
        puts("Wystąpił błąd zapisu do pliku");
        return 1;
    }
    int position = lseek(fdesc);

    return 0;
}
