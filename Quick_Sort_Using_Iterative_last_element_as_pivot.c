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
    int temp = arr[u];
    int i = l - 1;

    for(int j = l; j <= u-1; j++)
    {
        if(arr[j] <= temp)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[u]);
    return i+1;
}
void quickSortIterative(int *arr, int l, int u)
{
    // Create an auxiliary stack
    int stack[u - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = u;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        u = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, u);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < u) {
            stack[++top] = p + 1;
            stack[++top] = u;
        }
    }
}

void print(int *arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{

    int size;
    printf("Enter the size of the array:");

    scanf("%d", &size);
    int *arr = (int*)calloc(size, sizeof(int));

    printf("Enter %d numbers to get the sorted array:\n", size);
    for(int i =0; i<size; i++)
        scanf("%d", &arr[i]);

    printf("The array before sorting: ");
    print(arr, size);

    quickSortIterative(arr, 0, size-1);

    printf("The array after sorting; ");
    print(arr, size);

    return 0;
}