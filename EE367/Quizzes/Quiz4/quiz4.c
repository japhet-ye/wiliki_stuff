/*
 *
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void displayList(struct Node *head);
struct Node * destroyList(struct Node *head);
struct Node *deleteLast(struct Node *head);
struct Node *deleteNextToLast(struct Node *head);
struct Node *createList(int startVal, int finishVal);

struct Node *rotateLeft(struct Node *head, int k);

void main() 
{
struct Node *p = createList(3,13);
printf("List:\n");
displayList(p);
p = rotateLeft(p, 5);
printf("Rotated list to the left by 5 nodes:\n");
displayList(p);
p = destroyList(p);
}

struct Node *rotateLeft(struct Node *head, int k)
{
	// used to run the list
	struct Node *runner = head;
	// finds the node before the shift
	for(int i = 0;i<k-1;i++){
		runner = runner->next;
	}
	// printf("%d\n",runner->val); DEBUG
	// saves the old head
	struct Node* temp = head;
	// sets new head to next node
	head = runner->next;;
	// cuts the node off from new head value
	runner->next = NULL;
	// searches list until the end
	runner = head;
	while(runner->next != NULL){
		runner = runner->next;
	}
	// sets the end of the list to the old head
	runner->next = temp;
	return head;
}


void displayList(struct Node *head)
{
printf("List: ");
for (struct Node *p=head; p!=NULL; p=p->next) {
    printf("->%d ",p->val);
}
printf("\n");
}

struct Node * destroyList(struct Node *head)
{
struct Node *p = head;
while (p!=NULL) {
	struct Node *next = p->next;
	free(p);
	p = next;
}
return NULL;
}

struct Node *createList(int startVal, int finishVal)
{
struct Node *head = NULL;  /* Head of the list */
struct Node *last = NULL;  /* Last node in the list */
for (int i=startVal; i<=finishVal; i++) {
    /* Create node */
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->val = i;
    p->next = NULL;
    if (i == startVal) {
        head = p;
    }
    else {
	last->next = p;
    }
    last = p;
}
return head;
}


