#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 1000
#define NONCHAR '\0'

struct Stack {
	char * val;
	int size;
	int sp; /* Stack pointer */
};

struct Stack * createStack(int size);
void destroyStack(struct Stack *s);

char peek(struct Stack *stack);
void push(struct Stack *stack, char newval);
char pop(struct Stack *stack);
enum Bool isEmpty(struct Stack *stack);
void displayOutcome(char str[]);

enum Bool {false, true};
enum Bool isValid(char * str);

void main()
{
displayOutcome("()[]");
displayOutcome("(()[])");
displayOutcome("([)[])");
displayOutcome("([]]()");
displayOutcome("(([])[])");
displayOutcome("(([])[]");
}

/* Modfiy this function */
enum Bool isValid(char * str)
{

	struct Stack* circle = createStack(20);
	struct Stack* square = createStack(20);
	struct Stack* curly = createStack(20);
	// printf("Hello There\n");
	while(*str != '\0'){
		// printf("General Kenobi\n");
		if(*str == '('){
			push(circle,*str);
		}
		else if(*str == ')'){
			if(isEmpty(circle)){
				return false;
			}
			else{
				char temp = pop(circle);
			}
		}
		else if(*str == '['){
			push(square,*str);
		}
		else if(*str == ']'){
			if(isEmpty(square)){
				return false;
			}
			else{
				char temp = pop(square);
			}
		}
		else if(*str == '{'){
			push(curly,*str);
		}
		else if(*str == '}'){
			if(isEmpty(curly)){
				return false;
			}
			else{
				char temp = pop(curly);
			}
		}
		str++;
	}
	// printf("You are a bold one\n");
	if(isEmpty(circle) && isEmpty(square) && isEmpty(curly)){
		return true;
	}
	else{
		return false;
	}

	// int circle = 0; // ()
	// int square = 0; // []
	// int curly = 0; // {}
	// while(*str != '\0'){
	// 	if(*str == '('){
	// 		circle++;
	// 	}
	// 	else if(*str == ')'){
	// 		circle--;
	// 	}
	// 	else if(*str == '['){
	// 		square++;
	// 	}
	// 	else if(*str == ']'){
	// 		square--;
	// 	}
	// 	else if(*str == '{'){
	// 		curly++;
	// 	}
	// 	else if(*str == '}'){
	// 		curly--;
	// 	}
	// 	str++;
	// }
	// if(circle == 0 && square == 0 && curly == 0){
	// 	return true;
	// }
	// else{
	// 	return false;
	// }
}


void displayOutcome(char str[])
{
printf("String %s is",str);
if (isValid(str) == true) {
	printf(" valid\n");
}
else {
	printf(" invalid\n");
}

}


struct Stack * createStack(int size)
{
struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
stack->size = size;
stack->sp = -1;
stack->val = (char *) malloc(size*sizeof(char));
}

void destroyStack(struct Stack *stack)
{
free(stack->val);
free(stack);
}

char peek(struct Stack *stack)
{
if (stack->sp < 0) {
	return NONCHAR;
}
else {
	return stack->val[stack->sp];
}
}

void push(struct Stack *stack, char newval)
{
if (stack->sp < stack->size) {
	stack->sp++;
	stack->val[stack->sp] = newval;
}
}

char pop(struct Stack *stack)
{
if (stack->sp < 0) {
	return NONCHAR;
}
else {
	char c = stack->val[stack->sp];
	stack->sp--;
	return c;
}
}

enum Bool isEmpty(struct Stack *stack)
{
if (stack->sp < 0) return true;
else return false;
}


