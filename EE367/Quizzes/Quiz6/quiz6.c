#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

struct Node * createNode(char data);
struct Node * createTree(char encoding[], int *curr); 
void preorder(struct Node * root);
void inorder(struct Node * root);
void postorder(struct Node * root);

void main()
{
char tree1[] = "hzd//a//b/m//";
char tree2[] = "adt/i/m//h//fre//b///";

int curr = 0;
struct Node * root = createTree(tree1, &curr);
printf("Encoding: %s\n", tree1);
printf("Preorder: ");
preorder(root);
printf("\n");
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Postorder: ");
postorder(root);
printf("\n");

curr = 0;
root = createTree(tree2, &curr);
printf("Encoding: %s\n", tree2);
printf("Preorder: ");
preorder(root);
printf("\n");
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Postorder: ");
postorder(root);
printf("\n");

return;
}

void preorder(struct Node * root)
{
if (root==NULL) return;
printf("%c", root->data);
preorder(root->left);
preorder(root->right);
}

void inorder(struct Node * root)
{
if (root==NULL) return;
inorder(root->left);
printf("%c", root->data);
inorder(root->right);
}

void postorder(struct Node * root)
{
if (root==NULL) return;
postorder(root->left);
postorder(root->right);
printf("%c", root->data);
}

struct Node * createNode(char data)
{
struct Node *p = (struct Node *) malloc(sizeof(struct Node));
p->left = NULL;
p->right = NULL;
p->data = data;
}

struct Node * createTree(char encoding[], int *curr) 
{
if (encoding[*curr] == '/') { 
	return NULL;
}
struct Node *p = createNode(encoding[*curr]);
(*curr)++;
p->left = createTree(encoding, curr);
(*curr)++;
p->right = createTree(encoding, curr);

return p;
}


