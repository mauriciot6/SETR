#include <stdio.h>
#include <stdlib.h>

int main(void){

    int status = system("ps aux");              // system() devolve sempre um inteiro 0(se correr bem) ou -1(se correr mal)
    
    if(status == 1){
        perror("Erro so executar system()");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

// ps mostra uma fotografia dos processos atuais que estão acontecer no computador, e a flag aux indicam à ferramenta para mostrar processos 
// de todos os utilizadores (a), num formato orientado ao utilizador com detalhe de CPU/memoria (u), incluindo processos que não estão associados
// a um terminal (x).

// Para compilar:
// gcc -Wall -Wextra myPS.c -o myPS
// ./myPS