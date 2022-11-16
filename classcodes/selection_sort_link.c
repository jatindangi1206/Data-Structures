#include <stdio.h>
#include <stdlib.h>

//make a node

struct node {
    int data;
    struct node *next;
};

// printing the linked list by traversing it

void print_linked_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


// function to insert a new node at the end of the linked list

void append_node(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    // Incase of empty list 
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// selection sort algorithm for linked list 

void selection_sort(struct node **head) {
    struct node *current = *head;
    while (current != NULL) {
        struct node *min = current;
        struct node *j = current->next;
        while (j != NULL) {
            if (j->data < min->data) {
                min = j;
            }
            j = j->next;
        }
        // swap the data of the current node and the min node
        int temp = current->data;
        current->data = min->data;
        min->data = temp;
        current = current->next;
    }
}


int main (void) {
    int length;
    printf("Selection Sort Linked List Algorithm\n");
    printf("Enter the number of elements in your list: ");
    scanf("%d", &length);

    struct node *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        append_node(&head, current_val);
    }

    printf("The unsorted linked list is: ");
    print_linked_list(head);

    selection_sort(&head);

    printf("The sorted linked list is: ");
    print_linked_list(head);
}