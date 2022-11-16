#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// function to reverse the linked list

void reverse_linked_list(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}    



// function to insert a new node at the end of the linked list

void append_node(struct Node **head, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    // Incase empty list 
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// function to print the linked list
void print_linked_list(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// main function

int main(void) {
    int length;
    printf("Reverse Linked List Algorithm\n");
    printf("Enter the number of elements in your list: ");
    scanf("%d", &length);

    struct Node *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        append_node(&head, current_val);
    }

    printf("Given list: ");
    print_linked_list(head);

    reverse_linked_list(&head);
    printf("Reversed list: ");
    print_linked_list(head);
}