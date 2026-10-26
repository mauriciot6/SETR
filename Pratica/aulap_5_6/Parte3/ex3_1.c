#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){

    //criar um child process
    pid_t pid = fork();

    if(pid == -1){                  
        printf("Error in fork()");
        return 1;
    }else if(pid == 0){ 
        printf("I´m the child process! My PID = %d and my parent process (PPID) = %d\n", getpid(), getppid());
        fflush(stdout);         // Garante que cada mensagem é despejada imediatamente no terminal sem ficar retida no buffer
        //sleep(5)
    }else{
        printf("I´m the parent process! My PID = %d, and my child process PID = %d\n", getpid(), pid);
        fflush(stdout);
    }  
    
    printf("Process PID %d is finishing now\n", getpid());
    fflush(stdout);
    
    return 0;
}

/*
fork(), cria um novo processo(child process) duplicando  o processo que o chamou(parent process).
Quando a execução bate na linha pid_t pid = fork();, o sistema operativo faz um clone quase perfeito do teu processo na memória
A partir da linha imediatamente a seguir passam a existir dois processos independetes a executar o mesmo código em paralelo.

No Processo Filho: a função fork() devolve sempre 0
No Processo Pai: a função fork() devolve o PID (Process ID) do filho que acabou de criar
Em caso de erro: devolve -1

getpid(): devolve o PID do próprio processo que está a chamar a função
getppid() (Get Parent PID): devolve o PID do processo pai daquele processo

-> Se estás no Filho e queres o teu ID -> Chamas getpid()
-> Se estás no Filho e queres o ID do Pai -> Chamas getppid()
-> Se estás no Filho e leres a variável pid -> Vai ter sempre o valor 0
-> Se estás no Pai e queres o teu ID -> Chamas getpid()
-> Se estás no Pai e queres o ID do Filho -> Lês a variável pid

Para evitar que o processo pai acabe primeiro que o processo filho usamos as funções wait() ou waitpid() -> biblioteca -> #include <sys/wait.h>

waitpid() -> deixa especificar qual é o filho que o pai tem que esperar, no caso de haver mais de um filho

Ao meter o sleep(5), como pedido no 3.2 sem usar as funções wait(), vemos que o processo filho acaba depois do processo pai, onde mensagem é imprimida na linha de comandos onde eu escrevo:
I´m the parent process! My PID = 94642, and my child process PID = 94643
Process PID 94642 is finishing now
I´m the child process! My PID = 94643 and my parent process (PPID) = 94642
mauriciot6@LAPTOP-0OKD7MLK$ Process PID 94643 is finishing now !!!!!!!

Para evitar isso temos de usar o wait().
*/