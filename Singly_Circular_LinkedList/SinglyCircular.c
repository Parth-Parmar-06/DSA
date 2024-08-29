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
struct node* insertAt(struct node* head, int data, int pos) {
    struct node* newnode = createNewNode(data);
    int size = getSize(head);
    int index = 0;
    if (pos > size) {
        printf("Cannot insert at given position.\n");
        return head;
    } else if (pos == 0) {
        return insertFirst(head, data);
    } else if (pos == size) {
        return insertLast(head, data);
    } 
    struct node* temp = head;
    while (index < pos-1) {
        temp=temp->next;
        index++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
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
struct node* deleteAt(struct node* head, int pos) {
    if (head == NULL) return NULL;
    int size = getSize(head);
    if (pos >= size) {
        printf("Cannot delete at given position.\n");
        return head;
    }
    else if (pos == 0) return deleteFirst(head);
    struct node* temp = head, *prev;
    int index = 0;
    while (index < pos) {
        prev = temp;
        temp = temp->next;
        index++;
    }
    prev->next = temp->next;
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
    struct node* head = NULL;
    int choice, data, pos;

    printf("\nMenu:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete First Node\n");
    printf("5. Delete Last Node\n");
    printf("6. Delete Node at Position\n");
    printf("7. Display Linked List\n");
    printf("8. Get Size of Linked List\n");
    printf("9. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertFirst(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertLast(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (0-indexed): ");
                scanf("%d", &pos);
                head = insertAt(head, data, pos);
                break;
            case 4:
                head = deleteFirst(head);
                break;
            case 5:
                head = deleteLast(head);
                break;
            case 6:
                printf("Enter position to delete (0-indexed): ");
                scanf("%d", &pos);
                head = deleteAt(head, pos);
                break;
            case 7:
                displayLinkedList(head);
                break;
            case 8:
                printf("Size of Linked List: %d\n", getSize(head));
                break;
            case 9:
                exit(0);  
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
