#include <stdio.h>
#include <string.h>

void reverseString(char *str){

    char *start = str;                  /*criar dois ponteiros  para apontarmos para duas letras opsotas, por*/
    char *end = str;                    /*exemplo a primeira e a ultima para dp conseguirmos troca-las*/


    while(*end != '\0'){                /*Anvancamos o ponteiro ate encontar o final da string, o \0*/
        end++;                          /*Avancamos uma casa de memoria ate chegar ao fim*/
    }
    
    end--;                              /*Anda uma casa para tras para ir para a ultima letra*/

    while(start < end){                 /*Trocamos as letras ate o ponteiro do inicio for estiver antes do do fim*/
        
        char temp = *start;             /*troca das letras*/
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(void){

    char str[] = "Capoeira";
    
    printf("Palavra: %s\n", str);
    reverseString(str);
    printf("Palavra Invertida: %s\n", str);

    return 0;
}

/*Anexo:
Para o caso de ter de fazer copia alguma vez de um char:

/*int tamanho = strlen(str);                      /*Tamanho de str[], sem /0*/
/*char copiastr[tamanho+1];                       /*meter +1 para incluir o /0*/
/*strcpy(copiastr, str);                          /*copiar para a variavel copia o que esta na variavel str*/
