#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};


// function to reverse the linked list

void reverse_linked_list(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// function to insert a new node at the end of the linked list
void append_node(struct node **head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;

    // Incase empty list
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

// function to reverse the linked list


void reverse_till_k(struct node **head, int k) {
    int iterator = 1;
    struct node *temp_head = *head;
    while (iterator < k && temp_head != NULL) {
        temp_head = temp_head->next;
        iterator++;
    }

    // store the next node of the kth node
    struct node *saved_tail = temp_head->next;
    temp_head->next = NULL;

    reverse_linked_list(head);
    
    // Get to end of reversed linked list
    temp_head = *head;
    while (temp_head->next != NULL) {
        temp_head = temp_head->next;
    }
    temp_head->next = saved_tail;
}



// function to print the linked list
void print_linked_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    int length;
    printf("Algorithm for Range Based Reverse Linked Lists\n");
    printf("Enter the number of elements you want in your list: ");
    scanf("%d", &length);

    struct node *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        append_node(&head, current_val);
    }

    int k;
    printf("Enter the number of elements you want to reverse: ");
    scanf("%d", &k);

    printf("given list: ");
    print_linked_list(head);

    reverse_till_k(&head, k);
    printf("Reversed list: ");
    print_linked_list(head);
}