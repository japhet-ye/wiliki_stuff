#include <stdio.h>
#include <stdio.h>


int parenValid(char s[], int length);
int lengthString(char s[]);
void displayParenValid(char s[]);

void main()
{
char example1[] = "()(()())";
char example2[] = "(()(()())";
char example3[] = "(()())(())";
char example4[] = "())(()";
char example5[] = "(()(()";

displayParenValid(example1);
displayParenValid(example2);
displayParenValid(example3);
displayParenValid(example4);
displayParenValid(example5);


}
/* Currently the function doesn't work.  It just checks
 * if the string has even length, which is necessary
 * but not sufficient for a valid string of parens */
int parenValid(char s[], int length)
{
if (length%2 == 0){
    int valid = 0;
    for(int i = 0;i<length;i++){
        if(s[i] == ')' && valid == 0){ return 0; }
        else if(s[i] == '('){ valid++; }
        else if(s[i] == ')' && valid > 0){ valid--; }
    }
    if(valid == 0){ return 1; }
    else { return 0; } 
    }
else return 0;
}

int lengthString(char s[])
{
int k=0; 
for (; s[k]!='\0'; k++);
return k;
}

void displayParenValid(char s[])
{
printf("String '%s' is ",s);
if (parenValid(s, lengthString(s)) == 1) {
	printf("valid");
}
else {
	printf("invalid");
}
printf("\n");
}
