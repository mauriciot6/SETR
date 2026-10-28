#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

void *thread1(void *arg);
void *thread2(void *arg);

int main(void){

    pthread_t tid1, tid2;               // declaro duas variaveis do tipo pthread_t para guardar
                                        // os identificadores das duas novas threads

    printf("Main thread: creating two threads named 1 and 2\n");

    pthread_create(&tid1, NULL, thread1, NULL);         // cria e inicia a primeira thread(tid1) com atributos padrão (NULL), e executa a função thread1
    pthread_create(&tid2, NULL, thread2, NULL);
    
    pthread_join(tid1, NULL);           // colca a thread que  efetuou a chamada em espera até que esta termine. (Neste caso sem valor de retorno)
    printf("Thread1 Finishing\n");
    pthread_join(tid2, NULL);
    printf("Thread 2 finishing\n");

    printf("Main Thread: Both threads finished, exiting\n");

    return 0;
}

void *thread1(void *arg){
    printf("Thread 1 starting1n\n");
    pthread_exit(NULL);                         // termina a thread sem devolver valor de return
}

void *thread2(void *arg){
    printf("Thread2 executing\n");
    pthread_exit(NULL);                 
}

/*
Para compilar:
gcc ex5_1.c -o ex5_1 -pthread
./ex5_1

*/