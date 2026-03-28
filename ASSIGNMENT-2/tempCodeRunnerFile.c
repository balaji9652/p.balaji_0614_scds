/*Q1: Reverse a String using Stack
Write a C program to reverse a given string using a stack.
Example:
Input: DATA
Output: ATAD*/

/*Algorithm
1)Start
2)Declare a stack (array) and initialize top = -1
3)Read the input string
4)Traverse the string from left to right
   Push each character onto the stack
5)Traverse the string again
   Pop characters from the stack and store back into the string
6)Print the reversed string
7)Stop
*/


#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop operation
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    // Push all characters onto stack
    for (i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    // Pop characters to reverse string
    for (i = 0; i < strlen(str); i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s\n", str);

    return 0;
}