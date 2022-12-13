#include <stdio.h>
int main(void)
{
    int a[200], n, i, j, temp;
    
   // number of elements
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);

    // array elements
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // sorting
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }

    // sorted array printing 
    printf("Sorted list is:");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}