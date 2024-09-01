// #include<stdio.h>
// void enqueue(int Queue[], int front, int rear, int n, int x) {
//     if (rear == n - 1) {
//         printf("Overflow\n");
//     } else {
//         if (front == -1 && rear == -1) { 
//             front = rear = 0;
//         } else {
//             rear++;
//         }
//         Queue[rear] = x;
//         printf("Enqueued: %d\n", x);
//     }
// }
// int dequeue(int Queue[], int front, int rear) {
//     if (front == -1 && rear == -1) {
//         printf("Underflow\n");
//         return -1;
//     } else {
//         int y = Queue[front];
//         if (front == rear) { 
//             front = rear = -1;
//         } else {
//             front++;
//         }
//         printf("Dequeued: %d\n", y);
//         return y;
//     }
// }
// int main() {
//     int Queue[5];
//     int front = -1, rear = -1;
//     int n = 5, x, choice = 0;
//     while (choice != 3) {
//         printf("Enter 1 to enqueue, 2 to dequeue, 3 to exit: ");
//         scanf("%d", &choice);
//          if (choice == 1) {
//             printf("Enter the element you want to add: ");
//             scanf("%d", &x);
//             enqueue(Queue, front, rear, n, x);
//         } else if (choice == 2) {
//             dequeue(Queue, front, rear);
//         } 
    
//     }
// }

// write a program for Queue- equeue and dequeue operation

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

// Structure to represent a queue
typedef struct {
    int front, rear, size;
    int array[MAX];
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->size == MAX;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow: Unable to enqueue %d. The queue is full.\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX;  // Circular increment
    q->array[q->rear] = value;
    q->size++;
    printf("%d enqueued to queue.\n", value);
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Unable to dequeue. The queue is empty.\n");
        return -1;  // Return a sentinel value indicating underflow
    }
    int value = q->array[q->front];
    q->front = (q->front + 1) % MAX;  // Circular increment
    q->size--;
    return value;
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX;  // Circular indexing
        printf("%d\n", q->array[index]);
    }
}

int main() {
    Queue q;
    int choice, value;

    initQueue(&q);  // Initialize the queue

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("%d dequeued from queue.\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
