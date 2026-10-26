#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig){                  // função para manipualr os sinais

    switch(sig){                // avalia 
        case SIGINT:
            printf("Signal SIGINT recived (%d)\n", sig);
            break;
        case SIGHUP:
            printf("Signal SIGHUP recived (%d)\n", sig);
            break;
        case SIGUSR1:
            printf("Signal SIGUSR1 recived (%d)\n", sig);
            break;
        case SIGCONT:
            printf("Signal SIGCONT recived (%d)\n", sig);
            break;
        default:
            printf("Signal unknown recived\n");
            break;               
    }
    fflush(stdout);   
}

int main(void){

    struct sigaction sa;            // declarar uma struct onde vamos configurar o comportamneto dos sinais, guradando em sa

    sa.sa_handler = signal_handler;         // comentários abaixo
    sigemptyset(&sa.sa_mask);               // acede à gaveta sa_mask(que serve para definir qua outros sinais devem ser bloqueados enquanto a função executa)
                                            // e limpa-a garantindo que nenhum sinal extra fica bloqueado
    sa.sa_flags = 0;                // acede à terceira gaveta da caixa e desativa qualquer comportamento especial(colocando a zero)

    // Registar os 4 sinais, sigaction(configura um sinal de cada vez)
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGCONT, &sa, NULL);

    printf("Program in execution (PID: %d). Waiting for signals...\n", getpid());
    printf("To end the process, run another terminal: kill -KILL %d\n", getpid());
    fflush(stdout);

    while(1) {
        pause(); /*Suspende o processo ate chegar um sinal*/ 
    }

    return 0;
}




/*
Isto já existe
O molde original do Linux (simplificado)
struct sigaction {
    void (*sa_handler)(int);  // Gaveta 1: para guardar a função
    sigset_t sa_mask;         // Gaveta 2: para guardar os bloqueios
    int sa_flags;             // Gaveta 3: para guardar definições extra
};

!!!!!!
sa.sa_handler = signal_handler;
Aqui não estás a criar nada. Estás apenas a preencher uma gaveta que já existia
-> sa é a tua caixa
-> O ponto . é a instrução para abrir a caixa.
-> sa_handler é a gaveta específica onde o Linux exige que tu coloques a função de resposta aos sinais.
-> = é a instrução de atribuição (colocar lá dentro).
-> signal_handler é a função que tu escreveste umas linhas mais acima no código.

Tou a colocar na sa_handler, o endereço da função que criei em cima, que manipula os sinais recebidos


sigemptyset() serve para limpar essa gaveta de forma ssegura

sigaction(SIGINT, &sa, NULL);
É a chamada de sistema (syscall) que pega na tua caixa já totalmente preenchida e a entrega
ao núcleo do Linux (kernel), associando-a ao sinal específico

pause() returns only after a signal handler has executed.

Para compilar:
gcc -Wall ex4_1.c -o ex4_1
./ex4_1 &
Num outro terminal:
kill -USR1 <PID>
kill -HUP <PID>
kill -CONT <PID>
kill -INT <PID>
# Para encerrar definitivamente (já que o CTRL+C / SIGINT está a ser apanhado):
kill -KILL <PID>

!!
CTRL+C corresponde a um sinal muito específico chamado SIGINT (Signal Interrupt)

*/