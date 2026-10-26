#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    // verificar que o argc < 3 e que o numero de ficheiros é válido
    if(argc < 3 || atoi(argv[2]) < 1 || atoi(argv[2]) > 99){
        printf("Usage: %s <Group> <Number of files between 1 and 99>\n", argv[0]);
        return 1;
    }

    int i;
    int Nfolder = atoi(argv[2]);

    char folder_names[99][128];             // cria um array bidimensional de chars, que tem no limite 99 espaços, em que cada espaço tem 128 caracteres
                                            // serve para guardar o nome dos ficheiros

    // Vetor de ponteiros para meter no execvp() de tamanho 101-> 1 para mkdir, 99 para o numero maximo de ficheiros possivel, e +1 para o NULL
    char *argumentos[101];

    argumentos[0] = "mkdir";         // o primeiro paramentro é o nome do comando que vou utilizar, neste caso o mkdir

    for(i = 1; i<=Nfolder; i++){
        snprintf(folder_names[i-1], sizeof(folder_names[i-1]), "%s%d", argv[1], i);     // escreve o nome da pasta (ex: "Group1") na linha i-1 
        argumentos[i] = folder_names[i-1];      // guardar no array o endereço dessa pasta
    
        // Faço i-1 porque no array o primeiro elemneto vai ser o 0 e não o 1, uma vez que no for o i começa no 1 
    }

    argumentos[Nfolder+1] = NULL;        // o ultimo elemento a seguir ao numero de Folders tem de ser o NULL

    execvp("mkdir", argumentos);

    printf("Error executing execvp()");

    return 0;
}
/*
Tenho de criar um vetor para executar o excec() de uma vez só, porque sneão ele só iria criar um ficheiro

Para compilar:
gcc -Wall ex2_3.c -o ex2_3
./ex2_3 Group 3
*/