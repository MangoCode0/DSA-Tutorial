
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  

typedef struct {
    int top;
    char array[MAX];
} Stack;

void initStack(Stack* s) {
    s->top = -1; 
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow: Unable to push '%c'. The stack is full.\n", ch);
        return;
    }
    s->array[++(s->top)] = ch;
}
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Unable to pop. The stack is empty.\n");
        return '\0';  
    }
    return s->array[(s->top)--];
}
void reverseStringUsingStack(char* str) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }
    
    int i = 0;
    while (!isEmpty(&s)) {
        str[i++] = pop(&s); 
    }
    str[i] = '\0'; 
}

int main() {
    char str[MAX];
    
    printf("Enter a string to reverse: ");
    fgets(str, MAX, stdin);
    
    str[strcspn(str, "\n")] = '\0';
    
    reverseStringUsingStack(str);
    
    printf("Reversed string: %s\n", str);
       
    return 0;
}