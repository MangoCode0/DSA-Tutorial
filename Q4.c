
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    char arr[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = c;
    } else {
        printf("Stack Overflow!\n");
    }
}
char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1; 
    } else {
        return s->arr[(s->top)--];
    }
}

void reverseString(char* str) {
    Stack s;
    initStack(&s);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
