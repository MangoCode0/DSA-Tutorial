
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int top;
    int array[MAX];
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
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow: Unable to push %d. The stack is full.\n", value);
        return;
    }
    s->array[++(s->top)] = value;
    printf("%d pushed onto stack.\n", value);
}
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Unable to pop. The stack is empty.\n");
        return -1; 
    }
    return s->array[(s->top)--];
}
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1; 
    }
    return s->array[s->top];
}
void display(Stack* s) {cxr4
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->array[i]);
    }
}

int main() {
    Stack s;
    int choice, value;

    initStack(&s); 
    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("%d popped from stack.\n", value);
                }
                break;
            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Top element is %d.\n", value);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
