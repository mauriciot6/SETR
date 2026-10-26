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

    struct sigaction sa;

    sa.sa_handler = timer_signal_handler;
    sigemptyset(&sa.sa_mask);               // default
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGCONT, &sa, NULL);

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
Para compilar:
gcc -wall ex4_2 -o ex4_2
./ex4_2

noutro terminal
kill -INT PID
kill -HUP PID
kill -CONT PID

kill -KILL PID
*/