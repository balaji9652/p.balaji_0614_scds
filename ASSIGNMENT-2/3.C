/*Q3: Next Greater Element
Write a C program to find the Next Greater Element for each element in an array
using a stack.
Example:
Input: 4 5 2 10 8
Output:
4 → 5
5 → 10
2 → 10
10 → -1
8 → -1*/


/*Algorithm
1)Start
2)Read array elements
3)Initialize empty stack
4)Traverse array from right to left
        Pop elements smaller than or equal to current
        If stack empty → result = -1
        Else → result = top of stack
        Push current element to stack
5)Print results
6)Stop
*/



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