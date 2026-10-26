#include <unity.h>
#include "MyVectorLib.h"

void setUp(void)
{
		
	return;
}
void tearDown(void)
{
	return;
}

void test_MyVectorLib_Init(void)
{	
	MyVectorLib_Init();
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Len());	
}
	
void test_MyVectorLib_AddCheckSize(void)
{	
	MyVectorLib_Add(0);
	MyVectorLib_Add(27);
	MyVectorLib_Add(491);
	MyVectorLib_Add(520);
	MyVectorLib_Add(900);
	MyVectorLib_Add(3213);
	MyVectorLib_Add(12343);
	MyVectorLib_Add(999);
	TEST_ASSERT_EQUAL_INT(8, MyVectorLib_Len());	
}	

void test_MyVectorLib_Find_NotThere(void)
{
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Find(-14));	
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Find(40000));
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Find(999999));
}

void test_MyVectorLib_Find_AreThere(void)
{
	TEST_ASSERT_EQUAL_INT(1, MyVectorLib_Find(0));
	TEST_ASSERT_EQUAL_INT(2, MyVectorLib_Find(27));
	TEST_ASSERT_EQUAL_INT(5, MyVectorLib_Find(900));
	TEST_ASSERT_EQUAL_INT(8, MyVectorLib_Find(999));
	
}
void test_MyVectorLib_Len_RightSize(void)
{
	TEST_ASSERT_EQUAL_INT(8, MyVectorLib_Len());
}

void test_MyVectorLib_Remove(void){							/* Raciocinio para o teste: inserir 3 valores -> remover o do meio -> ver se o tamanho do vetor diminuiu */
	
	MyVectorLib_Init();										/* setup: garante que o vetor ta limpo */
	MyVectorLib_Add(10);									/* inserir valores no vetor */
	MyVectorLib_Add(20);
	MyVectorLib_Add(30);

	int remove = MyVectorLib_Remove(20);					/* Remover o 20 do vetor */

	TEST_ASSERT_EQUAL_INT(1, remove);						/* assume que a funcao devolve 1 se correu bem*/
	TEST_ASSERT_EQUAL_INT(2, MyVectorLib_Len());			/* testa se o tamanho do vetor passou de 3 para 2 */
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Find(20));			/* retorna 0 se tiver bem, uma vez que o 20 ja n existe a funcao n vai encontar o 20 */
}


void test_MyVectorLib_Sort(void){							/* Raciocinio para o teste: inserir valores baralhados -> pedir para enumerar -> verificar se a ordem ficou crescente */

	MyVectorLib_Init();										/* setup: garante que o vetor esta limpo */
	MyVectorLib_Add(5);										/* inserir os valores */
	MyVectorLib_Add(20);
	MyVectorLib_Add(10);

	MyVectorLib_Sort();										/* ordenar */

	TEST_ASSERT_EQUAL_INT(1, MyVectorLib_Find(5));			/* ve se na posicao 1 encontra o valor 5 no vetor */
	TEST_ASSERT_EQUAL_INT(2, MyVectorLib_Find(10));			/* ve se na posicao 2 encontra o valor 10 no vetor */
	TEST_ASSERT_EQUAL_INT(3, MyVectorLib_Find(20));			/* ve se na posicao 3 encontra o valor 20 no vetor */

}

void test_MyVectorLib_MAX_MIN_AVG(void){					/* Raciocinio: inserir valores -> chamar a funcao -> verificar os valores */

	MyVectorLib_Init();										/* setup */
	MyVectorLib_Add(5);										/* adicionar valores ao vetor */
	MyVectorLib_Add(10);
	MyVectorLib_Add(15);				

	TEST_ASSERT_EQUAL_INT(15, MyVectorLib_Max());			/* tem de retornar 15 que e o valor maximo para dar certo */
	TEST_ASSERT_EQUAL_INT(5, MyVectorLib_Min());			/* tem de retornar 5 o valor minimo para estar certo */
	TEST_ASSERT_EQUAL_INT(10, MyVectorLib_Avg());			/* 10 + 15 +5 = 30 / 3 = 10	tem de retornar 10 */
}


int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_MyVectorLib_AddCheckSize);			
	RUN_TEST(test_MyVectorLib_Find_NotThere);
	RUN_TEST(test_MyVectorLib_Find_AreThere);
	RUN_TEST(test_MyVectorLib_Len_RightSize);

	RUN_TEST(test_MyVectorLib_MAX_MIN_AVG);					/* chamar as funcoes para fazer o test */
	RUN_TEST(test_MyVectorLib_Remove);
	RUN_TEST(test_MyVectorLib_Sort); 
		
	return UNITY_END();
}
