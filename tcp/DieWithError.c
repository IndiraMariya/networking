#include <stdio.h>>
#include <stdlib.h>

void DieWithError (char *message){
    perror(message);
    exit(1);
}