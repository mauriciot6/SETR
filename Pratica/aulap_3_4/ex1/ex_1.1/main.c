#include <stdio.h>
#include <stdlib.h>                 /*Serve para chamar as funcoes rand() e srand()*/
#include <time.h>                   /*Serve para chamar a funcao time()*/

/*Gera um numero aleatorio entre 0 e 100 e conta quantas vezes a funcao foi chamada (sem depender da funcao main), para isso temos
que usar uma variavel static (apenas a funcao a ve mas entre chamadas n desaparece como se fosse uma variavel local)*/
/* value -> devolve o valor aleatorio*/
/* ncalls -> devolve o numero de vezes que foi chamada*/

void MyRand(int *value, int *ncalls){           /**/

    static int count = 0;
    
    count++;                                    /* a primeira chamada conta logo */
    *value = rand() % (100+1);                  /* numero entre 0 e 100 */
    *ncalls = count;                            /* devolve o numero de chamadas*/
}

int main(void){

    int value;
    int ncalls;
    int i = 0;

    srand(time(NULL));                          /*Tenho de usar isto uma unica vez no inicio do programa com base na hora atual 
                                                para fazer com que os numeros gerados no rand sejam sempre diferentes */
    for(i = 0; i < 5; i++){
        MyRand(&value, &ncalls);                /* Faco & para indicar o endereco das variaveis para a funcao alterar o valor, uma vez
                                                que ela so recebe enderecos*/
        printf("Chamada %d -> valor %d | ncalls = %d\n", i + 1, value, ncalls);
    }                                            
    return 0;                                        
}
/* Para compilar no terminal: gcc main.c -o main
   Para executar no terminal: ./main */