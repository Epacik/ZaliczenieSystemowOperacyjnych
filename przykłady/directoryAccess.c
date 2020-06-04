#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>
#include <limits.h>
#include <unistd.h>

extern int errno;

void ErrLog(){
    int errnum = errno;
    printf("Kod błędu: %d\n", errnum);
    printf((char*)strerror( errnum ));
    puts("\n");
}

void ErrLogAndClear(){
    ErrLog();
    errno = 0;
}

int main(void) {
    setlocale(0, "pl_PL");

    errno = 0;

    //odczytywanie obecnego katalogu
    char currDir[PATH_MAX];
    getcwd(currDir, sizeof(currDir));
    printf("Obecny katalog\n%s\n", currDir);

    //tworzenie katalogu
    int res = mkdir("./jakisKatalog", S_IRUSR | S_IWUSR | S_IXUSR);
    printf("res: %d\n", res);

    if(res == -1){
        ErrLogAndClear();
    }

    errno = 0;
    // Otwieranie katalogu
    DIR* dir = opendir(".");

    if(dir == NULL){
        ErrLogAndClear();
        return -1;
    }

    struct dirent *dp;

    errno = 0;
    //wypisywanie zawartości katalogu
    puts("Zawartość katalogu:\n");
    while ((dp = readdir (dir)) != NULL){
        printf("%s\n",dp->d_name);
    }

    if(dp == NULL && errno != 0){
        ErrLogAndClear();
        return -1;
    }
    else if(dp == NULL){
        puts("Koniec zawartości katalogu");
    }

    errno = 0;
    // zmiana katalogu
    res = chdir("./jakisKatalog");
    if(res == -1){
        ErrLogAndClear();
    }

    //sprawdzanie czy katalog rzeczywiście został zmieniony
    getcwd(currDir, sizeof(currDir));
    printf("Obecny katalog\n%s\n", currDir);
}