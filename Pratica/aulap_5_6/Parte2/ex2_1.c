#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    execlp("ps", "ps", "aux", (char*)NULL);     

    printf("Error executing execlp()\n");
    return 0;
}

/*
execlp("ps", "ps", "aux", (char*)NULL); -> 1º arguemnto diz ao sistema operativo qual ficheiro do programa é para abrir
2ª argumento -> serve para dar valor ao argv[0], tem de conter sempre o nome pelo qual o programa foi chamada
3ª argumento -> do terceiro em diante é para meter as flags
O último argumento é sempre o NULL -> (char*)NULL

as linhas abaixo do execlp só são executadas se o execlp falhar

Para compilar:
gcc -Wall ex2_1.c -o exe2_1
./ex2_1
*/