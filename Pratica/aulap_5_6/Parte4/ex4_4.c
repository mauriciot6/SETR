#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

volatile sig_atomic_t sigusr1_count = 0;            // global variable to count how mant times signal has recived

void child_sigurs1_handler(int sig){

    if(sig == SIGUSR1){
        sigusr1_count++;
    }
}

int main(void){

    struct sigaction sa;
    sa.sa_handler = child_sigurs1_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);

    pid_t pid = fork();                     // create child process


    if(pid == -1){
        printf("Error executing fork()\n");
    }else if(pid == 0){     
        // child process
        printf("I´m child process (PID %d), and i´m waiting to 10 URS1 signal from my grandparent process (PID %d)", getpid(), getppid());
        fflush(stdout);

        while(sigusr1_count < 10){
            pause();                // suspender até chegar o sinal, quando o sinal chega, o handler incrementa, até chegar aos 10
        
            printf("Child process: Recived SIGURS1 signal (%d/10)\n\n", sigusr1_count);
            fflush(stdout);
        }
        printf("Child: Recived all 10 signals.\n");
        exit(0);
    }else{
        //Grandparent process
        // ele envia os sinais

        int i;

        printf("Parent (PID: %d) sending to child(PID: %d)", getpid(), pid);
        sleep(1);               // dar tempo ao filho de executar e bloquear no pause
    
        for(i = 1; i<=10; i++){                 // repete 10 vezes

            kill(pid, SIGUSR1);                 // envia o sinal ao processo filho
            printf("Paren: Send SIGUSR1 signal (%d/10)", i);
            fflush(stdout);
            sleep(1);                           // para ser de um em um segundo
        }
    
        wait(NULL);                         // faz o processo pai esperar peli processo filho
        printf("Child Process terminated. Terminating parent...\n");
    }
    return 0;
}



