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
}