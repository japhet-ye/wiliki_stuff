/* The function 
 *
 * char * palin(char a[]); 
 *
 * will return the longest subsequence of a[] that is a palindrome.
 * The returned string will be terminted by the null byte '\0', 
 *
 * Implement this function so that it works properly using the top-down
 * approach with memoization.
 */


#include <stdlib.h>
#include <stdio.h>

#define STRINGSIZE 32

char msg[] = "Function 'palin2' must be implemented\n";

/* Utility functions */
char * createRandString(int length);
int ** createIntMatrix(int rowsize, int colsize); /* Creates a 2D int array */
void destroyIntMatrix(int **matrix);


char * palin(char a[]);

void main()
{
int k;
char * a = createRandString(STRINGSIZE);
printf("Input string=%s\n", a);

char * s = palin(a);
printf("palindrome = %s\n", s);
free(a);

a = createRandString(17);
printf("Input string=%s\n", a);
s = palin(a);
printf("palindrome = %s\n", s);
free(a);
}


char * palin(char a[])
{
return msg;
}

int ** createIntMatrix(int rowsize, int colsize)
{
int ** matrix = (int **) malloc((rowsize+1)*sizeof(int *));
for (int i=0; i<rowsize; i++) {
	matrix[i] = (int *) malloc(colsize*sizeof(int));
}
matrix[rowsize] = NULL;
return matrix;
}

void destroyIntMatrix(int **matrix)
{
for (int i=0; matrix[i]!=NULL; i++) {
	free(matrix[i]);
}
free(matrix);
}	

char * createRandString(int length)
{
srand48(1);
if (length < 1 || length > 1000000000) {
	return NULL;
}
char * a = (char *) malloc((length+1)*sizeof(char));
int i;
for (i=0; i<length; i++) {
	a[i] = 'a' + (char) (lrand48()%3);
}
a[i] = '\0';
return a;
}
