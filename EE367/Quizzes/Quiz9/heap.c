/*
 * heapSort implements heaport, which uses a max heap.
 * Function percolateDown doesn't work, and you must fix it.
 * Do not change the other functions.
 * Upload your code in laulima under Quiz 9.
 */


#include <stdlib.h>
#include <stdio.h>

#define RANDSEED 1
#define ARRAYSIZE 16

void randPermute(int a[], int length);
int randNum(int start, int end);
void fillArray(int a[], int length);
void displayArray(int a[], int length);
void swap(int *a, int *b);

int leftChild(int k);
int rightChild(int k);
int parent(int k);
void percolateDown(int a[], int length, int node);
void buildHeap(int a[], int length);
void heapSort(int a[], int length);


void main()
{
int a[ARRAYSIZE];
int length = ARRAYSIZE;

srand48(RANDSEED);

fillArray(a, length); 
printf("Initial values: ");
displayArray(a, length);

printf("\nArray with each iteration of heapsort:\n");
heapSort(a, length);

printf("\nFinal values: ");
displayArray(a, length);
}

void heapSort(int a[], int length)
{
buildHeap(a, length);
for (int k=length-1; k>0; k--) {
	swap(&a[0], &a[k]);
	percolateDown(a, k, 0);
	printf("Heapsort iteration: ");
	displayArray(a, length);
}
return;
}

void buildHeap(int a[], int length)
{
for (int k=length/2; k>=0; k--) {
	percolateDown(a, length, k);
}
return;
}

void percolateDown(int a[], int length, int node)
{
if(leftChild(node) >= length){
    return;
}
int max_node = node;
int left_child = leftChild(node);
int right_child = rightChild(node);
if(right_child < length && a[right_child] > a[max_node]){
    max_node = right_child;
}
if(left_child < length && a[left_child] > a[max_node]){
    max_node = left_child;
}
if(max_node != node){
    swap(&a[node],&a[max_node]);
    percolateDown(a,length,max_node);
}
return;
}

int leftChild(int k)
{
return 2*k + 1;
}

int rightChild(int k)
{
return 2*k + 2;
}

void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
return;
}

void displayArray(int a[], int length)
{
for (int k=0; k<length; k++) {
	printf("%d ", a[k]);
}
printf("\n");
}

void fillArray(int a[], int length)
{
for (int k=0; k<length; k++) {
	a[k] = k;
}
randPermute(a, length);
}

/* Randomly permutes the array a[] */
void randPermute(int a[], int length)
{
for (int k=0; k<length; k++) {
	int j=randNum(k,length-1);  /* Pick a random value */
	int temp = a[j];  /* Swap */
	a[j] = a[k];
	a[k] = temp;
}
}

/* Returns a random integer value in the interval [start, end] */
int randNum(int start, int end)
{
int size = end - start + 1;
return start + (lrand48()%size);
}