#include "configData.h"

uint16_t maxConnections;         /*variavel inicializada na memoria (variavel global),por isso n preciso
                                de usar ponteiros a variavel é visivel para todos os ficheiros*/

void configData_Init(void){
    maxConnections = 0;
}

void configSetMaxConnections(uint16_t value){
    maxConnections = value;
}

uint16_t configGetMaxConnections(void){
    return maxConnections;
}
