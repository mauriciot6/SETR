#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void){

    pid_t pid = fork();

    if(pid == -1){
        printf("Error executing fork()");
        return 1;
    }else if(pid == 0){
        // Child Process
        printf("I´m child process! My PID = %d, and my Parent is PID = %d\n", getpid(), getppid());
        fflush(stdout);
        sleep(5);                   // dar delay no child process
        printf("Work Done!!\n");
        fflush(stdout);
    }else{
        // Parent Process
        printf("I´m Parent process! My PID = %d, and my child PID = %d\n", getpid(), pid);
    
        // Make Parent Process wait
        int status;
        pid_t cpid = waitpid(pid, &status, 0);              // congela o processo pai, e depois gaurdar no enderço de memoria da variael status
                                                            // com as informações relativas ao filho, se já acabou ou não
                                                            // o 0 serve para ele funcionar em parametros normais
        if(status == -1){
            printf("Error executing waitpid()\n");
            return 1;
        }            
        
        if(WIFEXITED(status)){                  // se o processo filho acabou de forma natural
            printf("[Parent] The child process (PID %d) finish with exit code: %d\n", cpid, WEXITSTATUS(status));
            fflush(stdout);
        }
    }

    // Ambos os processos executam esta linha
    printf("Process PID %d is finishing now\n", getpid());
    fflush(stdout);

    return 0;
}

/*
WIFEXITED(status): É a pergunta. Devolve Verdadeiro (1) se o filho terminou normalmente. Usa-se sempre como condição num if
A macro WEXITSTATUS(status) extrai o número exato que o filho devolveu no fim (como o filho fez return EXIT_SUCCESS, vai imprimir 0)
*/