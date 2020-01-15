#include <stdlib.h>
#include <stdio.h>

#define RANDSEED 1
#define ARRAYSIZE 32

int randNum(int start, int end);
void randPermute(int a[], int length);
void fillArray(int a[], int length, int dupvalue);
void displayArray(int a[], int length);

int findDup(int a[], int length);

void main()
{
int a[ARRAYSIZE];
srand48(RANDSEED);

fillArray(a, ARRAYSIZE, 12); 
displayArray(a, ARRAYSIZE);
printf("Duplicate: %d\n", findDup(a, ARRAYSIZE));

fillArray(a, ARRAYSIZE, 23); 
displayArray(a, ARRAYSIZE);
printf("Duplicate: %d\n", findDup(a, ARRAYSIZE));

}

/* This takes too long */
int findDup(int a[], int length)
{
// since we know the size of the array
// and we know the content of the array since
// it will always be {1,2,3,4,...,n} with n-1 unique elements
// to find the duplicates, all we need to know the sum
// from 1 to (n-1)
// then sum up all the elements in the array
// since we know that there is only one duplicate
// the difference between the array sum and the
// expected sum is the duplicate value
// since we are not allowed to modify the array in any way
// and we are restricted to O(1) space complexity,
// and O(nlogn), I chose this algorithm
// this algorithm breaks if it is given an array of random numbers with 
// at least one duplicate pair (e.g {12,15,98,100,32,187,12183,12})
// the time complexity of this algorithm is O(n)
// the space-complexity of this algorithm is O(1)
int check_sum = 0;
int array_sum = 0;

for(int i = 0;i<length-1;i++){
	check_sum += i;
}

for(int i = 0;i<length;i++){
	array_sum += a[i];
}

return array_sum - check_sum;

// for (int k=0; k<length-1; k++) {
// 	for (int m=k+1; m<length; m++) {
// 		if (a[k] == a[m]) {
// 			return a[k];
// 		}
// 	}
// }
// return -1;
}

void displayArray(int a[], int length)
{
for (int k=0; k<length; k++) {
	printf("%d ", a[k]);
}
printf("\n");
}

void fillArray(int a[], int length, int dupvalue)
{
for (int k=0; k<length-1; k++) {
	a[k] = k;
}
a[length-1] = dupvalue;
randPermute(a, length);
}


/*
 * Randomly permutes the array a[] 
 */
void randPermute(int a[], int length)
{
for (int k=0; k<length; k++) {
	int j=randNum(k,length-1);  /* Pick a random value */
	int temp = a[j];  /* Swap */
	a[j] = a[k];
	a[k] = temp;
}
}

/*
 * Returns a random integer value in the interval [start, end]
 */
int randNum(int start, int end)
{
int size = end - start + 1;
return start + (lrand48()%size);
}

