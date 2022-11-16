#include <stdio.h>
#include <stdlib.h>
// making a node
struct MinHeapQueue {
    int *value;
    int maximum_size;
    int current_size;
};
// function to create a new node
int get_parent(int index) {
    return (index - 1) / 2;
}
// getting the left child
int get_left_child(int index) {
    return (2 * index) + 1;
}
// getting the right child
int get_right_child(int index) {
    return (2 * index) + 2;
}

int get_min_child(struct MinHeapQueue* ptr) {
    // Min Element of a min heap is always the root element
    return ptr->value[0];
}

struct MinHeapQueue* insert(struct MinHeapQueue* ptr, int value) {
    // if the heap is full
    if (ptr->current_size == ptr->maximum_size) {
        printf("Heap is full. Cannot insert %d", value);
        return ptr; 
    }
    // Insert the new element at the end of the heap
    ptr->value[ptr->current_size] = value;
    ptr->current_size++;
    int current_index = ptr->current_size - 1;
    int parent_index = get_parent(current_index);
    // bubble up
    while (parent_index >= 0 && ptr->value[parent_index] > ptr->value[current_index]) {
        int temp = ptr->value[parent_index];// swap the parent and the current node
        ptr->value[parent_index] = ptr->value[current_index];
        ptr->value[current_index] = temp;
        current_index = parent_index;// update the current index
        parent_index = get_parent(current_index); // update the parent index
    }
    return ptr;
}