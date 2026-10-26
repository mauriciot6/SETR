#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*Encapsulamento*/
typedef struct Node Node;

/*Prototipo das funcoes*/
void insertAtStart(Node **head, int new_data);
void insertAtPosition(Node **head, int new_data, int position);
void insertAtEnd(Node **head, int new_data);

void removeFromStart(Node **head);
void removeFromEnd(Node **head);
void removeFromPosition(Node **head, int position);

void printList(Node *node);

/*funcao usada para a file test*/
int getAtPosition(Node *head, int position);
#endif 