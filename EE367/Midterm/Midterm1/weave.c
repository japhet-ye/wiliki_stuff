/*
 *  Weave
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *weave(struct Node *head);

void displayList(struct Node *head);
struct Node * destroyList(struct Node *head);
struct Node *createList(int startVal, int finishVal);


void main() 
{
struct Node *p = createList(3,14);
printf("Original:\n");
displayList(p);
p = weave(p);
printf("Weaved:\n");
displayList(p);
p = destroyList(p);
}

struct Node *weave(struct Node *head)
{
if(head == NULL){ return NULL; }
else if(head->next == NULL){ return head; }
else{
    struct Node* prev = head;
    struct Node* front = head->next;
    struct Node* temp = front->next;
    head = front;
    head->next = prev;
    prev->next = temp;
    struct Node* temp_head = prev;
    while(temp != NULL){
        prev = temp_head->next;
        front = prev->next;
        temp = front->next;
        temp_head->next = front;
        front->next = prev;
        prev->next = temp;
        temp_head = prev;
    }
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

