#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int N, int M, float* avg, int* max, int*min);

int main(void){

    /*Gerar numeors aleatorios a cada execucao*/
    srand(time(NULL));                                          /*Meter sempre na main quanod uso a funcao rand*/

    int N = 10;
    int M = 50;

    float avg;
    int max, min;                                        /*criei as variaveis onde vou meter os valores do avg, max e min*/

    /*Chamar a funcao que cria o array*/
    int* arr = createArray(N, M, &avg, &max, &min);             /*Indicar para onde ir os enderecos de cada parametro da funcao*/


    /*Imprimir o array*/
    printf("Array: [");
    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

    /*Imprimir avg, max e min*/
    printf("Avg: %.2f\n", avg);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    free(arr);                                                      /*Libetar memoria*/

    return 0;
}

int* createArray(int N, int M, float* avg, int* max, int*min){            /*N-> array size, M-> array Max Value*/

    /*Para criar o array se fizer da forma nomal-> int arr[N], ele vai ser desfeito acda vez que a funcao acabar, logo tenho de 
    pedir espaco ao sistema operativo, usando a funcao malloc (Memory Allocation)*/

    /*Pedimos para guardar espaco para N blocos do tamanho de um inteiro*/
    int* arr = (int*)malloc(N * sizeof(int));  
    int soma = 0;
    
    /*Ciclo para gerar os numeros aleatorios1*/
    for(int i = 0; i<N; i++){
        /*Gera um numero aleatorio entre 1 e M*/
        arr[i] = (rand() % M) + 1;                          /*Gerar numeros aleatorio: ir anexo abaixo*/

        /*Somar cada numero gerado para depois calcular a media*/
        soma += arr[i];

        /*Max e Min*/
        if(i==0){                               /*Assumir que o primeiro elemento e simultaneamente maximo e minimo*/
            *max = arr[i];
            *min = arr[i];
        }else{
            if(arr[i] > *max){                  /*Compara o valor novo avalor do array com o maximo atual e se for maior subsitui*/
                *max = arr[i];
            }
            if(arr[i] < *min){                  /*O mesmo para aqui*/
                *min = arr[i];
            }
        }
    }

    /*Calculo da media*/
    *avg = (float)soma / N;                     /*Fazemos float cast a soma para n perder as casas decimais (questao cast -> ver anexo)*/

    return arr;                                 /*Anexo*/
}

/*Anexo:
Gerar numeros aleatorios:
-> a funcao rand gera um numero aleatorio de qualquer quantidade de digitos, se quero por exemplo entre 1 e 100, tenho sempre
de fazer o resto da divisao (%), para obter um numero entre 0 e 99, somo 1 neste exmeplo porque quero entre 1 e 100.
Se quisesse entre 0 1 100, como sao 101 numero faria rand() % 100+1

Cast:
-> ao fazer neste caso (float)soma, obriga a divisao a ser no formato float e n no formato int ja que a soma era uma variavel int,
caso n o fizessemos a divisao iria ser uma divisao de interios onde o resultado seria um inteiro e nao um float como suposto

Return arr, Porque?
-> dou return do array uma vez que tenho de ao fim da funcao ser executada todas as variaveis locais incluindo o array que criei
se perdem, ao dar return do array que esta alocado na memoria n perco esses enderecos, conseguindo usa-los na funcao main.
*/