#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = newData;
    
    newNode->next = *head;
    newNode->prev = NULL;
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
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

    insertAtBeginning(&head, 10);  
    insertAtBeginning(&head, 20); 
    insertAtBeginning(&head, 30);  
    insertAtBeginning(&head, 40);  

    printListForward(head);
    printListReverse(head);

    return 0;
}
