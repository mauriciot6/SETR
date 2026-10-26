#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc < 3 || atoi(argv[2]) < 1 || atoi(argv[2]) > 99){

        printf("Usage: %s <Group> <number of folders between 1 and 99>", argv[0]);
        return 1;
    }

    int nFolder = atoi(argv[2]);
    int i, status;

    char cmd[256];
    char confirm;

    for(i = 1; i<=nFolder; i++){
 
        snprintf(cmd,sizeof(cmd), "rmdir %s%d", argv[1], i);
        status = system(cmd);

        if(status != 0){                    // quando dá erro, porque mdir só apaga pastas vazias
            
            while(1){

                printf("\n%s%d Folder is not empety. Remvove anyway? Answer; Y/y or N/n", argv[1], i);
                scanf("%c", &confirm);          // lê um char e guarda na variável confirm
                
                if(confirm == 'y' || confirm == 'Y'){
                    snprintf(cmd, sizeof(cmd), "rm -r %s%d", argv[1], i);
                    system(cmd);
                    break;
                }else if(confirm == 'n' || confirm == 'N'){
                    break;
                }else{
                    printf("Answer: Yy or N/n\n");
                }
            }
         }

    }
    return 0;
}


/*
rmdir apenas elimina pastas vazias
rm -r elimina pastas e o que está dentro delas

Para compilar:
gcc -Wall ex1_4.c -o ex1_4
./ex1_4 Group 2
*/