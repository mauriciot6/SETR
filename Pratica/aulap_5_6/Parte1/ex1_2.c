#include <stdio.h>
#include <stdlib.h>

// wc comand -> analisa ficheiros de texto
// usar man wc no terminal para ver no momento para saber uqe prefixo usar
// -w (words): print the number of words
// -m (chars): print the number of caracters

int main(int argc, char *argv[]){

    // Validar se o utilizador passou o nome do ficheiro
     if(argc < 2){                                      // <2 porque se for menor que 2 quer dizer que o user n meteu o nome do file txt
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    
    char cmd[256];              // simula a linha de comandos, uma vez que o system só aceita receber uma string
    snprintf(cmd, sizeof(cmd), "wc -w -m %s", argv[1]);

    int status = system(cmd);

    if (status == -1) {
        perror("Erro ao executar system()");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;    
}


 
// Na int main, o argc serve para o programa ler o que o utilizador vai escrever no terminal. O argc é o número inteiro que diz quantas palavras
// separadas por espaços o utilizador escreveu no terminal.
// O vetor argv, é um array de strings que contém exatamente as palavras que o utilizador escreveu
// Ex: se no terminal escrever: ./ex1_2 filetext.txt
// o argc será 2, e o argv[0] será: "./ex1_2" e o argv[1] será "filetext.txt"

//snprintf serve para imprimir o texto dentro de uma variavel, neste caso o cmd, em vez de imprimir para o ecrã

// caso quisesse garantir que o ficheiro caso tenha espaço n é lido com dois, faria: "wc -w -m \"%s\"", metia aspas para ele ler tudo com um só ficheiro

// compilar no terminal: 
// gcc -Wall -Wextra ex1_2.c -o ex1_2
// ./ex1_2 ex1_2.c filetext.txt