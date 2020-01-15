/*
 * Is the array row- or column-major?
 */


#include <stdio.h>
#include <stdlib.h>

void main() {

int array[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
int *p = *array;

for (int i=0; i<9; i++) {
   printf("%d\n",p[i]);
}

}


