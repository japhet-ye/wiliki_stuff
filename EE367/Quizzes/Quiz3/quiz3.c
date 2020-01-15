/*
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define NEWNODEVAL 5

struct Node {
    int val;
    struct Node *next;
};

void displayList(struct Node *head);
struct Node *createList(int startVal, int finishVal);
struct Node * destroyList(struct Node *head);
struct Node * createNode(int val);

struct Node *deleteLast(struct Node *head);
struct Node *appendNode(struct Node *head, struct Node * new);
struct Node *deleteNode(struct Node *head, int val);

int size_of_list(struct Node *head);

void main() 
{
struct Node *p = createList(3,13);
printf("Created list:\n");
displayList(p);

p = deleteLast(p);
printf("Deleted last node:\n");
displayList(p);

struct Node *new = createNode(NEWNODEVAL);
printf("Created node %d\n",new->val);

p = appendNode(p, new);
printf("Appended node:\n");
displayList(p);

p = deleteNode(p, NEWNODEVAL);
printf("Deleted node %d:\n",NEWNODEVAL);
displayList(p);

p = destroyList(p);
printf("Destroyed list:\n");
displayList(p);
}
int size_of_list(struct Node *head){
	int size = 1;
	struct Node* runner = head;
	for(;runner->next!=NULL;size++){
		runner = runner->next;
	}
	// printf("%d\n",size);
	return size;
}
struct Node *deleteLast(struct Node *head)
{
	int size = size_of_list(head);
	if(head == NULL) { return NULL; }
	struct Node* runner = head;
	for(int i = 1; i<size - 1; i++){
		runner = runner->next;
	}
	runner->next = NULL;
	// size = size_of_list(head);
	return head;
}

struct Node *appendNode(struct Node *head, struct Node * new)
{
	if(head == NULL){ return new;}
	struct Node* runner = head;
	while(runner->next != NULL){
		runner = runner->next;
	}
	runner->next = new;
	return head;
}

struct Node *deleteNode(struct Node *head, int val) 
{
	// printf("I am sam\n");
	if(head == NULL){ return NULL;}
	else{
		// printf("Sam I am\n");
		struct Node* runner = head;
		if(runner->val == val) { return runner->next; }
		else{
			// printf("That Sam I am\n");
			while(runner->val != val){
				runner=runner->next;
			}
			// printf("I do not like that Sam I am\n");
			while(runner->next != NULL){
				runner->val = (runner->next)->val;
				runner = runner->next;
			}
			// printf("Then do you not like green eggs and ham?\n");

		} 
		// printf("No I do not like green eggs and ham\n");
		head = deleteLast(head);
		// printf("Do you like them here?\n");

	}
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

struct Node * createNode(int val)
{
struct Node *new = (struct Node *) malloc(sizeof(struct Node));
new->val = val;
new->next = NULL;
return new;
}
