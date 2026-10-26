#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;                              /*variavel temporario para armazenar o valor*/    

    *a = *b;                                    /*le o valor de b e escreve por cima do endereco do a*/
    *b = temp;                                                              
}

int main(void){

    int a = 10;
    int b = 20;

    printf("Valor inicial de a: %d, e de b: %d\n", a, b);
    swap(&a, &b);
    printf("Valor trocado de a: %d, e de b: %d\n", a, b);

    return 0;
}