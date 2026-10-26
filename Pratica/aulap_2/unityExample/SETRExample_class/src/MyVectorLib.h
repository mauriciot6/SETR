#ifndef MYVECTORLIB_H
#define MYVECTORLIB_H

#define MYVECTLIB_MAXLEN 	10		/* Maximum size of vector 			*/

/* Return codes - *** DO NOT USE MAGIC NUMBERS *** */
#define MYVECTLIB_OK		0		/* Success return code code			*/
#define MYVECTLIB_NOTFOUND	0		/* Number not found					*/

/* Function prototypes */
void MyVectorLib_Init(void); 		/* Initializes the vector			*/
int MyVectorLib_Add(int number);	/* Adds a number to the vector		*/
int MyVectorLib_Find(int number); 	/* Finds if a number exists in the vector	*/
int MyVectorLib_Len(void);			/* Returns the length of the vector	*/

int MyVectorLib_Remove(int number);         /* Function to remove one element from the vector */
void MyVectorLib_Sort(void);                /* Function to sort the vector (enumerar) */

int MyVectorLib_Max(void);                  /* Function to compute Max value */
int MyVectorLib_Min(void);                  /* Function to compute Min value */
int MyVectorLib_Avg(void);                  /* Function to compute average */

#endif
