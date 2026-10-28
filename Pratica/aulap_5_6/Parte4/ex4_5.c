#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

volatile sig_atomic_t counter = 0;

void singalHandler(int sig){

    if(sig == SIGUSR1){
        counter++;
        printf("Recived SIGUSR1. Counter = %d\n", counter);
        fflush(stdout);

        sleep(15);              // tempo para testar o bloqueio do sinal SIGUSR2    

        printf("Finish processing SIGUSR1\n");
        fflush(stdout);
    }else if(sig == SIGUSR2){

        printf("Recived SIGUSR2 and executed it\n");
        fflush(stdout);
    }
}

int main(void){

    struct sigaction sa;
    struct sigaction sa2;

    // Configurar o SIGUSR1

    sa.sa_handler = singalHandler;
    sigemptyset(&sa.sa_mask);                   // primeiro limpo a mascara para depois adicionar o sinal SIGUSR2
    sigaddset(&sa.sa_mask, SIGUSR2);            // bloqueio a execução do SIGUSR2 enquanto o handler tiver a executar, fica em espera o SIGUSR2
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);

    // configurar o SIGUSR2

    sa2.sa_handler = singalHandler;
    sigemptyset(&sa2.sa_mask);
    sa2.sa_flags = 0;

    sigaction(SIGUSR2, &sa2, NULL);

    printf("Executing (PID: %d). Waiting for signals...\n", getpid());

    while(1){
        pause();
    }
}







/*
Neste exercicio tenho de ter uma config
diferentes --> os dois sinais exigem regras de 
bloqueio diferentes
    
SIGUSR1 - A máscara precisa de incluir o SIGUSR2 (usando sigaddset) 
para garantir que este é bloqueado temporariamente enquanto o handler
do SIGUSR1 está a ser executado.

SIGUSR2 - A máscara fica limpa (vazia) pois é suposto
manter o comportamento normal do sinal

EXECUTAR O PROGRAMA:

./ex_4p5 & --> executa o programa no background de modo a conseguir
enviar os sinais SIGUSR1 e SIGUSR2 no mesmo terminal

*/