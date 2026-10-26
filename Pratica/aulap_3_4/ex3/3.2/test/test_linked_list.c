#include <unity.h>
#include <stdlib.h>
#include "linked_list.h"

static Node *head = NULL;

/* Corre automaticamente ANTES de cada funcao de teste */
void setUp(void) {
    head = NULL; /* Garante que cada teste comeca com a lista vazia */
}

/* Corre automaticamente DEPOIS de cada funcao de teste */
void tearDown(void) {
    /* Limpa a memoria caso o teste tenha deixado elementos na lista */
    while (head != NULL) {
        removeFromStart(&head);
    }
}

/*Test funcao inserir no inicio*/
void testInsertAtStart(void){

    insertAtStart(&head, 20);
    insertAtStart(&head, 10);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(10, getAtPosition(head, 1));
    TEST_ASSERT_EQUAL_INT(20, getAtPosition(head, 2));
}

void testInsertAtPosition(void){
    insertAtStart(&head, 20);
    insertAtStart(&head, 10);
    insertAtPosition(&head, 15, 2);

    TEST_ASSERT_EQUAL_INT(10, getAtPosition(head, 1));
    TEST_ASSERT_EQUAL_INT(15, getAtPosition(head, 2));
    TEST_ASSERT_EQUAL_INT(20, getAtPosition(head, 3));
}

void testInsertAtEnd(void){
    insertAtStart(&head, 20);
    insertAtStart(&head, 10);
    insertAtEnd(&head, 30);

    TEST_ASSERT_EQUAL_INT(10, getAtPosition(head,1));
    TEST_ASSERT_EQUAL_INT(20, getAtPosition(head,2));
    TEST_ASSERT_EQUAL_INT(30, getAtPosition(head,3));
}

void testRemoveFromStart(void){
    insertAtStart(&head, 20);
    insertAtStart(&head, 10);
    insertAtEnd(&head, 30);

    removeFromStart(&head);

    TEST_ASSERT_EQUAL_INT(20, getAtPosition(head,1));
    TEST_ASSERT_EQUAL_INT(30, getAtPosition(head,2));
    TEST_ASSERT_EQUAL_INT(-1, getAtPosition(head,3));           /*ver se ja nao existe*/
}

void testRemoveFromPosition(void){
    insertAtStart(&head, 20);
    insertAtStart(&head, 10);
    insertAtEnd(&head, 30);

    removeFromPosition(&head, 2);

    TEST_ASSERT_EQUAL_INT(10, getAtPosition(head,1));
    TEST_ASSERT_EQUAL_INT(30, getAtPosition(head,2));       /*ver se o 10 foi para a segunda posicao*/
    TEST_ASSERT_EQUAL_INT(-1, getAtPosition(head,3));       /*ver se ja nao ha posicao 3*/
}

void testRemoveFromEnd(void){

    insertAtStart(&head, 20);
    insertAtStart(&head, 10);
    insertAtEnd(&head, 30);

    removeFromEnd(&head);

    TEST_ASSERT_EQUAL_INT(10, getAtPosition(head,1));
    TEST_ASSERT_EQUAL_INT(20, getAtPosition(head,2));
    TEST_ASSERT_EQUAL_INT(-1, getAtPosition(head,3));           /*ver se ja nao existe*/
}

int main(void){

    UNITY_BEGIN();

    RUN_TEST(testInsertAtStart);
    RUN_TEST(testInsertAtPosition);
    RUN_TEST(testInsertAtEnd);
    RUN_TEST(testRemoveFromStart);
    RUN_TEST(testRemoveFromEnd);
    RUN_TEST(testRemoveFromPosition);

    return UNITY_END();
}
