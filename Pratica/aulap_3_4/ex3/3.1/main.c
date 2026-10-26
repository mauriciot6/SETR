#include <stdio.h>
#include <stdlib.h>             /*para usar o malloc*/


typedef struct Node{                    /*estruta para fazer o no*/
    int data;
    struct Node *next;                  /*endereco do proximo elemento*/
}Node;                                  /*nome pelo qual vou chamar o no*/

void insertAtStart(Node **head, int new_data){      /*Ponteiro duplo para conseguirmos mudar na main a head
                                                    da lista e ao fazer apenas um ponetiro n iria alterar, iria apenas alterar a sua copia*/
    Node *new_node = (Node*)malloc(sizeof(Node));   /*Alogamos espaco fisico na memoria do tamanho exato da nossa struct, o malloc devolve
                                                    o endereco desse espaco e guardamos no ponteiro new_node*/
    new_node->data = new_data;              /*Copiamos o numero que recebemos nos argumentos da funcao para dentro do comprimento data do nosso no*/
    new_node->next = *head;                 /*O novo no precisa de se ligar ao resto da lista, fazemos que o campo next aponte para onde era a antiga head para n perdermos os elementos antigos*/
    *head = new_node;                       /*O novo no passa a ser a head (primeiro elemento)*/
}

/*Inserir um elemento em qualquer lugar da lista*/
void insertAtPosition(Node **head, int new_data, int position){
    
    if (position < 1) {
        printf("Erro: A posicao tem de ser maior ou igual a 1.\n");
        return;
    }

    if (position == 1){                         /*chama a funcao para meter no inicio*/
        insertAtStart(head, new_data);
        return;
    }

    Node *temp = *head;             /*criar um ponteiro temporario que comeca na head, precisamos dele para andar pela lista, sem perder a referencia head*/

    for(int i = 1; i<position - 1 && temp != NULL; i++){    /*temp !=NULL serve para o programa nao explodir(ver melhor depois)*/
        /*Avanca o ponteiro ate parar no no anterior(position -1 ), no sitio onde queremos colocar o novo elemento*/                            
        temp = temp->next;                                  
    }

    if(temp == NULL){
        printf("Erro: A posicao %d esta para alem do fim da lista!\n", position);
        return;
    }

    Node*new_node = (Node*)malloc(sizeof(Node));            /*o mesmo que n funcao inserAtStart*/
    new_node->data = new_data;
    new_node->next = temp->next; 
    temp->next = new_node;            
}

void insertAtEnd(Node **head, int new_data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;              /*alugamos memoria para o novo no, e como vai ser o ultimo da lista o next aponta par ao NULL*/

    // Se a lista estiver vazia, o novo no passa a ser a cabeca
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Caminhar ate ao ultimo no
    Node *temp = *head;
    while (temp->next != NULL) {            /*percorre a lista ate ao fim*/
        temp = temp->next;                  /*o poneteiro avanca ate ao NULL (onde vai ficar o ultimo elemnto)*/
    }
    temp->next = new_node;                  /*quando o encontra, agarra no next dele e cola-o ao new_node*/              
}

void removeFromStart(Node **head){

    if (*head == NULL) {
        printf("Erro: A lista esta vazia!\n");
        return;
    }

    Node *temp = *head;             /*guardamos temporariamento o endereco da ehad para n o perdermos*/
    *head = (*head)->next;           /*a head passa logo para o elemento a seguir (neste caso o segundo) ligando assim as listas*/
    free(temp);                     /*liberta a memoria do antigo primeiro no (eliminando assim o elemento)*/
}

void removeFromEnd(Node **head){

    if (*head == NULL) {
        printf("Erro: A lista esta vazia!\n");
        return;
    }

    /*Para o caso de a lista ter aoenas um elemento*/
    if ((*head)->next == NULL) {
        free(*head);                    /*apaga o unico elemento que existe*/
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while(temp->next->next != NULL){        /*O ciclo avanca o ponteiro temp ate parar estritamente no penultimo no*/
        temp = temp->next;                  /*verificando se o next->next e NULL (se o elemnto a seguir e NULL, logo o next e o ultimo)*/
    }
    /*Ao chegar ao penultimo, libertamos a memoria no next, e transformamos o next no NULL para apontar para o fim da lista*/
    free(temp->next);                      
    temp->next = NULL;
}

void removeFromPosition(Node **head, int position){

    if (*head == NULL) {
        printf("Erro: A lista esta vazia!\n");
        return;
    }
    if (position < 1) {
        printf("Erro: Posicao invalida.\n");
        return;
    }
    if (position == 1) {
        removeFromStart(head);
        return;
    }

    Node *temp = *head;                                         /*o mesmo que para o insertAtPosition*/
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Erro: Posicao fora dos limites da lista!\n");
        return;
    }

    Node *nodeToDelete = temp->next;            /*identificamos e guardamos numa variavel temporaria o elemnto a ser eliminado*/
    temp->next = nodeToDelete->next;            /*o no anterior (temp), vai ligar ao no que vinha a seguir do elemnto a eliminar*/
    free(nodeToDelete);                         /*eliminamos o elemento*/
}

void printList(Node *node){

    printf("List: ");
    while(node != NULL){                /*percorre a lista enquanto o ponteiro n bate no NULL (fim)*/
        printf("%d -> ", node->data);   /*Imprime o valor atual*/         
        node = node->next;              /*node->next faz saltar para o proximo no*/
    }
    printf("NULL\n");
}


int main(void){

    Node *head = NULL;                  /*No inicio o ponteiro head comeca apontar para o NULL porque a lista esta vazia inicialmente*/
    insertAtStart(&head, 30);
    insertAtStart(&head, 10);

    printf("Lista inicial:\n");
    printList(head);

    printf("\nInserir o 20 na posicao 2:\n");
    insertAtPosition(&head, 20, 2);

    printList(head);
    
    printf("\nInserir o 40 no fim\n");
    insertAtEnd(&head, 40);
    
    printList(head);

    printf("\nRemover do inicio:\n");
    removeFromStart(&head);

    printList(head);

    printf("\nRemover do fim:\n");
    removeFromEnd(&head);

    printList(head);

    printf("\nRemover da posicao 2:\n");
    removeFromPosition(&head, 2);

    printList(head);

    return 0;
}