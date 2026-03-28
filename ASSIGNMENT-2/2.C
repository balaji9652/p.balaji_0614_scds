/*Q2: Balanced Parentheses
Write a C program using a stack to check whether the parentheses in an expression are
balanced.
Example:
Input: (A+B)*(C-D)
Output: Balanced Expression*/


/*Algorithm
1)Start
2)Initialize empty stack
3)Read expression
4)For each character:
     Push opening brackets
     For closing brackets:
        If stack empty → Not Balanced
        Pop and check match
5)If stack empty → Balanced, else Not Balanced
6)
Stop*/


#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int match(char a, char b) {
    return (a=='('&&b==')') || (a=='{'&&b=='}') || (a=='['&&b==']');
}

int main() {
    char exp[MAX];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(i=0; i<strlen(exp); i++) {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if(top==-1 || !match(pop(), exp[i])) {
                printf("Not Balanced Expression\n");
                return 0;
            }
        }
    }

    if(top==-1)
        printf("Balanced Expression\n");
    else
        printf("Not Balanced Expression\n");

    return 0;
}