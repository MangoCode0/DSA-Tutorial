// write a program to reverse a string using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Maximum size of the stack

// Structure to represent a stack
typedef struct {
    int top;
    char array[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;  // Indicates that the stack is empty
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push a character onto the stack
void push(Stack* s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow: Unable to push '%c'. The stack is full.\n", ch);
        return;
    }
    s->array[++(s->top)] = ch;
}

// Function to pop a character from the stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Unable to pop. The stack is empty.\n");
        return '\0';  // Return a null character indicating underflow
    }
    return s->array[(s->top)--];
}

// Function to reverse a string using stack
void reverseStringUsingStack(char* str) {
    Stack s;
    initStack(&s);
    
    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }
    
    // Pop each character from the stack and store it in the string
    int i = 0;
    while (!isEmpty(&s)) {
        str[i++] = pop(&s);
    }
    str[i] = '\0';  // Null-terminate the reversed string
}

int main() {
    char str[MAX];
    
    // Input the string to reverse
    printf("Enter a string to reverse: ");
    fgets(str, MAX, stdin);
    
    // Remove the newline character from the string if it exists
    str[strcspn(str, "\n")] = '\0';
    
    // Reverse the string using stack
    reverseStringUsingStack(str);
    
    // Output the reversed string
    printf("Reversed string: %s\n", str);
    
    return 0;
}
