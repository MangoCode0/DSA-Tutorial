#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = newData;
    newNode->next = NULL; 
    newNode->prev = NULL; 

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;  
}

void printListForward(struct Node* head) {
    struct Node* temp = head;
    printf("Forward Traversal: ");
    
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printListReverse(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Reverse Traversal: ");
    
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);  
    insertAtEnd(&head, 20);  
    insertAtEnd(&head, 30);  
    insertAtEnd(&head, 40);  

    printListForward(head);
    printListReverse(head);

    return 0;
}
