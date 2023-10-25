#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create() {
    int n, data;
    struct Node *newNode, *temp;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = data;
    head->next = head;
    temp = head;
	int i;
    for ( i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }
    printf("Circular linked list created.\n");
}

void insert() {
    int data, position;
    struct Node *newNode, *temp;
    if (head == NULL) {
        printf("The list is empty. Please create the list first.\n");
        return;
    }

    printf("Enter data to be inserted: ");
    scanf("%d", &data);
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        printf("Node inserted at the beginning.\n");
        return;
    }

    temp = head;
    int i;
    for ( i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Invalid position.\n");
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

void delete() {
    int position;
    struct Node *temp, *prev;
    if (head == NULL) {
        printf("The list is empty. Please create the list first.\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        temp = head;
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
        printf("Node at the beginning deleted.\n");
        return;
    }

    temp = head;
    prev = NULL;
    int i;
    for ( i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("Invalid position.\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
    printf("Node at position %d deleted.\n", position);
}

void reverse() {
    struct Node *current, *prev, *next;
    if (head == NULL) {
        printf("The list is empty. Please create the list first.\n");
        return;
    }

    current = head;
    prev = NULL;
    while (current->next != head) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current->next = prev;
    head = current;
    printf("List reversed.\n");
}

void concatenate() {
    struct Node *temp1, *temp2;
    if (head == NULL) {
        printf("The list is empty. Please create the list first.\n");
        return;
    }

    int n, data;
    printf("Enter the number of nodes to concatenate: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    temp1 = head;
    while (temp1->next != head) {
        temp1 = temp1->next;
    }
	int i;
    for ( i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;

        temp1->next = newNode;
        temp1 = newNode;
    }

    printf("List concatenated.\n");
}

void display() {
    struct Node* temp;
    if (head == NULL) {
        printf("The list is empty. Please create the list first.\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nCircular Linked List Operations\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Reverse\n");
        printf("5. Concatenate\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                reverse();
                break;
            case 5:
                concatenate();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

