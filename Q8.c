#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtMiddle(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* slow = *head;
    struct Node* fast = *head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    newNode->next = slow->next;
    slow->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtMiddle(&head, 10);  
    insertAtMiddle(&head, 20);  
    insertAtMiddle(&head, 30);  
    insertAtMiddle(&head, 40);  
    insertAtMiddle(&head, 25); 

    printf("Linked List after insertion at middle: ");
    printList(head);

    return 0;
}
