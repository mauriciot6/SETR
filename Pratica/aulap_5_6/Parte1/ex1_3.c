#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    // Verificar o numero de argumentos de argc
    if(argc < 3 || atoi(argv[2]) < 1 || atoi(argv[2]) > 99){
        printf("Usage: %s <Group> <Number of Folders (1 to 99)>", argv[0]);
        return 1;
    }

    int nFolder = atoi(argv[2]);
    int i;
    char cmd[256];

    // ciclo para cirar as pastas de 1 até n
    for(i=1; i <= nFolder; i++){

        snprintf(cmd, sizeof(cmd), "mkdir %s%d", argv[1], i);               // o i vai se ro numero do ficheiro
        system(cmd);
    }
    return 0;
}


/*
O programa vai receber dois argumentos na linha de comandos: Group 10, ou seja argc=3, e o argv[0] = "./ex1_3", o argv[1] = "Group" e o argv[2]= "10" 
como o argv[2] vai se rum numero: n, temos de o converter para inteiro, usando a função atoi

Para compilar:
gcc -Wall ex1_3.c -o ex1_3
./ex1_3 Group 2
*/





