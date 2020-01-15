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
struct Node *createList(int startVal, int finishVal);

struct Node *reverse(struct Node *head);
struct Node *removeKthfromEnd(struct Node *head, int k);
struct Node *reorderList(struct Node *head);
int lengthOfList(struct Node * head);

void main() 
{

struct Node *p = createList(3,13);
printf("\nCreated a list:\n");
displayList(p);
p = reverse(p);
printf("Reversed the list:\n");
displayList(p);
p = destroyList(p);

p = createList(3,13);
printf("\nCreated a list:\n");
displayList(p);
p =removeKthfromEnd(p, 5);
printf("Removed 5-th from end:\n");
displayList(p);
p = destroyList(p);


p = createList(3,13);
printf("\nCreated a list:\n");
displayList(p);
p =reorderList(p);
printf("Reordered list:\n");
displayList(p);
p = destroyList(p);

p = createList(3,12);
printf("\nCreated a list:\n");
displayList(p);
p =reorderList(p);
printf("Reordered list:\n");
displayList(p);
p = destroyList(p);

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

struct Node *reverse(struct Node *head)
{
	struct Node* runner = head;
	struct Node* temp1 = malloc(sizeof(struct Node));
	temp1->val = runner->val;
	while(runner->next!= NULL){
		runner = runner->next;
		struct Node* temp2 = malloc(sizeof(struct Node));
		temp2->val = runner->val;
		temp2->next = temp1;
		temp1 = temp2;
		
	}
	head = destroyList(head);
	return temp1;
}

struct Node *removeKthfromEnd(struct Node *head, int k)
{
	struct Node* runner = head;
	// printf("Length of List : %d \n",lengthOfList(head));
	int length = lengthOfList(head);
	return head;
}

struct Node *reorderList(struct Node *head)
{
return head;
}

int lengthOfList(struct Node * head){
	struct Node * runner = head;
	int length = 1;

	for(;runner->next != NULL;length++){
		runner = runner->next;
	}
	return length;
}
