#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;

};

struct Node* insertAtBeginning(struct Node* head, int value)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data= value;
    newNode->next= head;
    return newNode;
} 
struct Node* insertAtEnd(struct Node* head, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
     
    newNode->data = value; 
    newNode->next = NULL; 
  
    if (head == NULL) { 
        return newNode; 
    } 
 
    struct Node* temp = head; 
  
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
 
    temp->next = newNode;  
    return head; 
} 
 
struct Node* insertAtPosition(struct Node* head, int value, int pos) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
 
    if (pos == 1) { 
        newNode->next = head; 
        return newNode; 
    } 
 
    struct Node* temp = head; 
  
    for (int i = 1; i < pos - 1 && temp != NULL; i++) { 
        temp = temp->next; 
    } 
 
    if (temp == NULL) { 
        printf("Invalid Position!\n"); 
        return head; 
    } 
 
    newNode->next = temp->next; 
    temp->next = newNode; 
 
    return head; 
} 
 
void display(struct Node* head) { 
    struct Node* temp = head; 
 
    if (temp == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
 
    printf("Linked List: "); 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
int main() { 
    struct Node* head = NULL; 
 
    head = insertAtBeginning(head, 30); 
    head = insertAtBeginning(head, 20); 
    head = insertAtBeginning(head, 10); 
 
    display(head); 
 
    head = insertAtEnd(head, 40); 
    head = insertAtEnd(head, 50); 
 
    display(head); 
 
    head = insertAtPosition(head, 25, 3); 
 
    display(head); 
 
    return 0; 
}
