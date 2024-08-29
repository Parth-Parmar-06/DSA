#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* createNewNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
int getSize(struct node* head) {
    if (head == NULL) return 0;
    struct node* temp = head;
    int size = 1;
    while (temp->next != head) {
        temp = temp->next;
        size++;
    } return size;
}
struct node* insertFirst(struct node* head, int data) {
    struct node* newnode, *temp=head;
    newnode = createNewNode(data);
    if (head == NULL) {
        head = newnode;
        head->next = newnode;
        return head;
    }
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
    return head;
}
struct node* insertLast(struct node* head, int data) {
    struct node* newnode = createNewNode(data);
    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
        return head;
    }
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    } 
    temp->next = newnode;
    newnode->next = head;
    return head;
}
struct node* deleteFirst(struct node* head) {
    struct node *temp = head, *deletedEle;
    if (head == NULL) {
        return NULL;
    } else if (head->next == head) {
        free(head);
        return NULL;
    }
    while (temp->next != head) {
        temp = temp->next;
    }
    deletedEle = head;
    head = head->next;
    temp->next = head;
    free(deletedEle);
    return head;
}
struct node* deleteLast(struct node* head) {
    struct node *temp = head, *prev;
    if (head == NULL) {
        return NULL;
    } else if (head->next == head) {
        free(head);
        return NULL;
    }
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    return head;
}
void displayLinkedList(struct node* head) {
    struct node* temp = head;
    if (head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp->next != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    } printf("%d\n", temp->data);
}
int main() {
    struct node* head=NULL;
    displayLinkedList(head);
    head = insertFirst(head, 10);
    head = insertFirst(head, 5);
    displayLinkedList(head);
    int size = getSize(head);
    printf("Size: %d\n", size);
    head = insertLast(head, 20);
    displayLinkedList(head);
    head = deleteLast(head);
    displayLinkedList(head);
    // head = deleteFirst(head);
    // displayLinkedList(head);
    // head = deleteFirst(head);
    // displayLinkedList(head);
    return 0;
}