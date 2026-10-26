#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if(argc < 3 || atoi(argv[2]) < 2 || atoi(argv[2]) > 99){
        printf("Usage %s <Group> <Number of folders between 1 and 99>", argv[0]);
        return 1;
    }

    int i;                          // para o ciclo for
    int nFolder = atoi(argv[2]);
    char folder_name[99][128];

    char *argumentos[102];          // 1 para "rm", 1 para a flag "-r", 99 para o numero de folders e 1 para o NULL

    argumentos[0] = "rm";
    argumentos[1] = "-r";

    for(i=1; i <= nFolder; i++){
        snprintf(folder_name[i-1], sizeof(folder_name[i-1]), "%s%d", argv[1], i);
        argumentos[i+1] = folder_name[i-1];             // argumentos[i+1], porque o i começa no 1 e eu quero meter a partir do lugar 2 do array, os 2 primeiros já estão ocupados
    }

    argumentos[nFolder+2] = NULL;

    execvp("rm", argumentos);

    printf("Error executing execvp()");

    return 0;
}

/*Fazer depois usando o fork() apagar as pastas com o mkdir, e qaundo der erro por tar cheia apagar usando o rm -r*/

/*
Para compilar:
gcc -Wall ex2_4.c -o ex2_4
./ex2_4 Group 3
*/