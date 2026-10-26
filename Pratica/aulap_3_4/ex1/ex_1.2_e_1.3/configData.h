#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <stdint.h>

/* Usasse o extern para declarar a variavel e n definir, isto diz ao compilador que a variavel existe
mas vai ser declarada num outro ficheiro, neste caso no .c, isto no 1.2*/
/*extern uint16_t maxConnections; No 1.3 isto desaparece para n ser visto pelos outros ficheiros, apenas e declarada no ConfigData.c*/  

void configData_Init(void);
void configSetMaxConnections(uint16_t value);           /*Set the value of maxConnections*/
uint16_t configGetMaxConnections(void);                 /*Get the value of maxConnections*/

#endif