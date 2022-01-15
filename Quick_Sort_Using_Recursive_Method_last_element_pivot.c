#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int u)
{
    int pivot = arr[u];
    int i = l - 1;

    for(int j = l; j <= u - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[u]);
    return (i+1);
}

void quickSort(int *arr, int l, int u)
{
    if(l < u)
    {
        int p = partition(arr, l, u);

        quickSort(arr, l, p-1);
        quickSort(arr, p+1, u);
    }
}

void display(int *arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int *arr, size;
    printf("Enter the size of the array:");

    scanf("%d", &size);
    arr = (int*)calloc(size, sizeof(int));

    printf("Enter %d elements in the array:", size);
    for(int i = 0; i<size; i++)
        scanf("%d", &arr[i]);

    printf("Original Array: ");
    display(arr, size);

    quickSort(arr, 0, size-1);

    printf("Sorted Array: ");
    display(arr, size);

    return 0;
}