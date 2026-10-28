#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>

#define NEXECUTIONS 10

volatile bool flag = 0;
volatile int counter = 0;

void *thread1(void *arg);                   // vai dar upadate
void *thread2(void *arg);                   // vai dar print

int main(void){

    pthread_t tid1, tid2;

    printf("Main Thread: Creating twdo threads name 1 and 2\n");

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Threads 1 and 2 finished, terminate main thread...\n");
    
    return 0;
}

void *thread1(void *arg){
    
    while(counter <= NEXECUTIONS){
        sleep(1);
        counter ++;
        flag = 1;                   // sinalizar mudança na variavel counter
    }
    pthread_exit(NULL);
}

void *thread2(void *arg){

    while(counter <= NEXECUTIONS){
        if(flag == 1){
            printf("Elaped counter %d\n", counter);
            fflush(stdout);
            flag = 0;               // retornar a flag a 0 para poder ser modifcado de novo quanod o counter incrementar
        }else{
            flag = 0;
        }
        usleep(1000);               // Para n sobrecarrgar o CPU no polling
    }
    pthread_exit(NULL);
}



