#include <stdio.h>
#include "configData.h"


int main(void){

    /*Ex 1.2*/
    /*Inicializar a variavel maxConnection usando a funcao*/
    /*configData_Init();
    printf("Value after first Init: %u\n", maxConnections);

    /*Modificar diretamente o valor de maxConnections*/
    /*maxConnections = 100;
    printf("Value after first modificatio: %u\n", maxConnections);

    /*Ler e modificar de novo o valor com o valor atual*/
    /*maxConnections += 50;
    printf("Value after beign modified using the previous value: %u\n", maxConnections);

    /*Voltar a dar inicializao para ver se volta a ser 0*/
    /*configData_Init();
    printf("Value after initialization again: %u\n", maxConnections);

    return 0;
    */
    
    /*Ex 1.3*/
    configData_Init();
    printf("Valor apos a inicializacao: %u\n", configGetMaxConnections());      /*le o valor*/

    configSetMaxConnections(10);                                                /*Altera o valor usando a funcao */
    printf("Valor apos modificacao: %u\n", configGetMaxConnections());            /*le o novo valor*/

    configData_Init();
    printf("Valor de nova inicializacao: %u\n", configGetMaxConnections());

    return 0;
}
/*Para compilar:
    gcc main.c configData.c -o main
Para correr:
    ./main
*/