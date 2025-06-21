//write a program for circular Queue- enqueue and dequeue operation

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int front, rear, size;
    int array[MAX];
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isFull(CircularQueue* q) {
    return q->size == MAX;
}

int isEmpty(CircularQueue* q) {
    return q->size == 0;
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow: Unable to enqueue %d. The queue is full.\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX; 
    q->array[q->rear] = value;
    q->size++;
    printf("%d enqueued to queue.\n", value);
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Unable to dequeue. The queue is empty.\n");
        return -1; 
    }
    int value = q->array[q->front];
    q->front = (q->front + 1) % MAX; 
    q->size--;
    return value;
}

void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX;  
        printf("%d\n", q->array[index]);
    }
}

int main() {
    CircularQueue q;
    int choice, value;

    initQueue(&q); 

    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
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
