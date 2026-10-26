#include <string.h> 		/* For memset */
#include "MyVectorLib.h"

static int MyVectorLib_Vect[MYVECTLIB_MAXLEN]; 	/* Vector */
static int MyVectLen=0;							/* Number of elements in the vector*/

/* Initializes the vector */
void MyVectorLib_Init(void){
	MyVectLen=0;
	memset(MyVectorLib_Vect,0,sizeof(MyVectorLib_Vect));
	return;
} 		

/* Adds an element to the vector */
int MyVectorLib_Add(int number){
	MyVectorLib_Vect[MyVectLen++]=number; 	/* Missing something ? (ja esta bem) */
	return MYVECTLIB_OK;
}	

/* Returns the position of number (is it an index or ordinal?)  (ja esta bem)*/
int MyVectorLib_Find(int number)
{
    int i = 0;
        
    while (i < MyVectLen) {		
        if (MyVectorLib_Vect[i] == number)
			return (i+1);
		i++;
	}
	
    return MYVECTLIB_NOTFOUND;
}

/* Returns the number of elements in the vector */
int MyVectorLib_Len(void)
{
	return MyVectLen;
}

int MyVectorLib_Remove(int number){

	int i;											/* variavel para o ciclo for */
	int index_to_remove = -1;

	/* procurar o indice do elemento a remover */
	for(i=0; i < MyVectLen; i++){
		if(MyVectorLib_Vect[i] == number){
			index_to_remove = i;
			break;
		}
	}

	/* Se nao encontrar o indice retorna 0 (falha) */
	if(index_to_remove == -1){
		return 0;
	}

	/* Puxar os elementos seguintes um casa para a esquerda */
	for(i = index_to_remove; i < MyVectLen - 1; i++){			/* o for comeca no indice que foi removido ate ao ultimo indice -1 , uma vez que foi removido um elemnto, */
																/* o vetor ficou mais pequeno, e iguala a posicao atual do vetor com a seguinte. */
		MyVectorLib_Vect[i] = MyVectorLib_Vect[i+1];
	}

	MyVectLen --;											/* diminuiu o tamanho do vetor */

	return 1;	/* sucesso */												
}	

void MyVectorLib_Sort(void){

	int i;
	int j;
	int temp;

	/* Precisamos para ordenar dois ciclos for, uma apenas n chega, um apenas agarante que o maior de todos fica no final, precismaos de outro ciclo para repetir  */ 
	/*os ciclos mais vezes. Se temos um vetor com tamanho N, precisamos de N-1 ciclos para conseguir ordenar todos os numeros do vetor*/ 

	for(i = 0; i < MyVectLen - 1; i++){									/* vai do 0 ate o indice N-1, porque se temos um vetor com tamanho N, precisamos de N-1 ciclos*/ 
																	/* para conseguir ordenar todos os numeros do vetor*/
		for(j = 0; j < MyVectLen - i - 1; j++){						/* este ciclo faz percorrer o vetor da esquerda para a direita , comparando e fetuando as trocas*/
																	/* no final de cada ciclo do primeiro for vamos ter o maior numero do vetor sendo empurrado ate a ultima posicao do vetor */
			if(MyVectorLib_Vect[j] > MyVectorLib_Vect[j + 1]){		/*compara dos elementos vizinhos e ve se e preciso trocar a ordem */
				temp = MyVectorLib_Vect[j];							/* se for preciso torcar: guardar o maior valor num variavel temporaria */
				MyVectorLib_Vect[j] = MyVectorLib_Vect[j + 1];		/* copia o valor do numeor menor para a posicao do maior */
                MyVectorLib_Vect[j + 1] = temp;						/* e depois volta a copiar o maior para a posicao do menor, tendo sido assim a troca feita */
			}												
		}
	}
}

int MyVectorLib_Max(void){

	if(MyVectLen == 0){						/* caso de o vetor estar vazio*/
		return 0;
	}

	int i;

	int max = MyVectorLib_Vect[0];						/* assume o primeiro numero o maior, vai comprar com os restantes ate encontrar um maior */
	for(i = 1; i < MyVectLen; i++){				/* logo comeca no segundo elemento */
		if(MyVectorLib_Vect[i] > max){					/* se for maior que o max faz atualiza o valor de max */
			max = MyVectorLib_Vect[i];
		}
	}
	return max;
}

int MyVectorLib_Min(void){
	
	if(MyVectLen == 0){						/* caso de o vetor estar vazio */
		return 0;
	}

	int i;

	int min = MyVectorLib_Vect[0];				/* assume o numero como o min */
	for(i = 1; i < MyVectLen; i++){				/* logo comeca no segundo elemento */
		if(MyVectorLib_Vect[i] < min){			/* se for maior que o max faz atualiza o valor de max */
			min = MyVectorLib_Vect[i];
		}
	}
	return min;
}

int MyVectorLib_Avg(void){

	if(MyVectLen == 0){						/* caso de o vetor estar vazio */
		return 0;
	}

	int i;

	int soma = 0;
	for(i = 0; i < MyVectLen; i++){
		soma += MyVectorLib_Vect[i];				/* soma todos os valores */
	}
	return soma / MyVectLen;						/* faz a media */
}