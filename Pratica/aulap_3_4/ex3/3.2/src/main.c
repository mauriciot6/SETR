#include <stdio.h>
#include "linked_list.h"


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


