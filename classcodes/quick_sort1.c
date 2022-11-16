#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // if current item is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // swap arr[i+1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
// low is the starting index, high is the ending index
void quick_sort(int unsorted_list[], int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = partition(unsorted_list, low, high);
    quick_sort(unsorted_list, low, pivot - 1);
    quick_sort(unsorted_list, pivot + 1, high);
}
// print array
void print_array(int array[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// quick sort
int main(void) {
    int len;
    printf("Quick Sort\n");
    printf("Enter how many numbers you want in the list: ");
    scanf("%d", &len);

    int unsorted_list[len];
    for (int i = 0; i < len; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%d", &unsorted_list[i]);
    }

    printf("Unsorted array: ");
    print_array(unsorted_list, len);
    
    quick_sort(unsorted_list, 0, len - 1);

    printf("Sorted array: ");
    print_array(unsorted_list, len);
}