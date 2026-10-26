#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//criar variáveis globais
volatile sig_atomic_t elapsed_seconds;        // conta os segundos decorridos 
volatile sig_atomic_t is_running = 1;               // variavel que diz se o tempo está ativo ou parado

void timer_signal_handler(int sig){

    switch(sig){

        case SIGINT:
            elapsed_seconds = 0;
            is_running = 1;
            printf("Time reseted and now is count has resumed...\n");
            break;
        case SIGHUP:
            is_running = 0;
            printf("Suspended count\n");
            break;
        case SIGCONT:
            is_running = 1;
            printf("Count resumed\n");
            break;
    }
    fflush(stdout);
}

int main(void){

    struct sigaction sa_catch;              // struct para interpretar os sinais desejadas
    struct sigaction sa_ignore;             // struct para ignorar sinais indesejados

    // configurar struct que ignora sinais

    sa_ignore.sa_handler = SIG_IGN;             // signal ignore, instrui o kernel a descratar qualquer sinal associado a esta struct
    sigemptyset(&sa_ignore.sa_mask);             
    sa_ignore.sa_flags = 0;

    // ciclo para ignorar todos os sinais exeto o SIGKILL E SIGSTOP
    for(int sig = 1; sig < 32; sig++){           // percorre os 31 sinais 
        if(sig == SIGKILL || sig == SIGSTOP){
            continue;
        }
        sigaction(sig, &sa_ignore, NULL);           // Aplica a regra SIG_IGN a todos os sinais do ciclo, todos são ignorados
    }

    // configurar struct que interpreta os devidos sinais

    sa_catch.sa_handler = timer_signal_handler;
    sigemptyset(&sa_catch.sa_mask);                      // sinais possíveis do programa         
    sa_catch.sa_flags = 0;

    sigaction(SIGINT, &sa_catch, NULL);
    sigaction(SIGHUP, &sa_catch, NULL);
    sigaction(SIGCONT, &sa_catch, NULL);

    printf("Count start (PID= %d)\n", getpid());
    printf("Commands: SIGINT (Reset) | SIGHUP (Suspend the counting) | SIGCONT (Resumes the counting)\n");
    fflush(stdout);

    while(1){

        if(is_running == 1){
            printf("Elapsed Time: %d\n", (int)elapsed_seconds);
            fflush(stdout);
            sleep(1);
            if(is_running == 1){            // faço de novo para o caso de o sinal SIGHUP tenha interrompido o sleep(1)
                elapsed_seconds++;
            }else{
                pause();
            }
        }
    }

    return 0;
}

/*
Para o sistema operativo, os nomes dos sinais não existem, são apenas números inteiros.
por exmeplo: 
-> SIGHUP 1
-> SIGINT 2
-> SIGKILL 9
-> SIGUSR1 10
Até o 31.


O que faz se estiver vazia (sigemptyset)?

Se deixares a máscara vazia, significa que não quero bloquear nenhum sinal extra
O sigfillset() é exatamente o oposto do sigemptyset(). Enquanto o sigemptyset() limpa a máscara (não bloqueia nada extra),
o sigfillset() enche a máscara com todos os sinais possíveis do sistema.

perguntar da mask ao stor, um bocado confuso
*/