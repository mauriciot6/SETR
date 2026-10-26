#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if (argc < 2) {
        printf("Usage: %s fileName", argv[0]);
        return 1;
    }

    // Substituir o processo atual pelo comando "wc -w -m <ficheiro>"
    execlp("wc", "wc", "-w", "-m", argv[1], (char*)NULL);        // uso argv[1] para dizer ao fim das flags qual o nome do ficheiro

    printf("Error executing execlp\n");

    return 0;
}

