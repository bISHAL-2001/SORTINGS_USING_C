#include <stdio.h>
#include <stdlib.h>
int partition(int *arr, int l, int u)
{
    int pivot = arr[l];
    while(l <= u)
    {
        while(arr[l] < pivot)
            l++;
        while(arr[u] > pivot)
            u--;
        if(l <= u)
        {
            int temp = arr[l];
            arr[l] = arr[u];
            arr[u] = temp;
            l++;
            u--;
        }
    }
    return l;
}
void quickSort(int *arr, int l, int u)
{
    int p = partition(arr, l, u);

    if(l < p-1)
        quickSort(arr, l, p-1);
    if(u > p)
        quickSort(arr, p, u);

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
    printf("Enter %d elements:", size);
    for(int i = 0; i<size; i++)
        scanf("%d", &arr[i]);
    
    printf("The Original Array: ");
    display(arr, size);

    quickSort(arr, 0, size-1);
    printf("The Sorted Array: ");
    display(arr, size);

    free(arr);
}