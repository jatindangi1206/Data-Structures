#include <stdio.h>



void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// selection sort
void selection_sort(int unsorted_numbers[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int a = i + 1; a < size; a++) {
            if (unsorted_numbers[a] < unsorted_numbers[min]) {
                min = a;
            }
        }
        // swap with min with i by storing i in temp variable
        int temp = unsorted_numbers[i];
        unsorted_numbers[i] = unsorted_numbers[min];
        unsorted_numbers[min] = temp;
    }
}





int main(void) {
    int size;
    printf("Selection Sort\n");
    printf("Enter how many elements you want in your array: ");
    scanf("%d", &size);

    int unsorted_numbers[size];
    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &unsorted_numbers[i]);
    }

    printf(" Unsorted array : ");
    print_array(unsorted_numbers, size);
    
    selection_sort(unsorted_numbers, size);

    printf(" Sorted array: ");
    print_array(unsorted_numbers, size);
}