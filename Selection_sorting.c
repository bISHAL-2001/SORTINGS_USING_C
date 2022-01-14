/*
 * The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
 *  1) The subarray which is already sorted.
 *  2) Remaining subarray which is unsorted.
 *  In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
 *  Time Complexity: O(n2) as there are two nested loops.
    Auxiliary Space: O(1)
    The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
 */

/* C program for implementation of selection sort*/
#include <stdio.h>
#include <stdlib.h>

/*Function to swap 2 values*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*Function to sort an array using Selection Sort*/
void selectionSort(int *arr, int n)
{
    int i, j, min_idx;

    /* One by one to move boundary of unsorted subarray*/
    for (i = 0; i < n-1; i++)
    {
        /* Find the minimum element in unsorted array*/
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        /* Swap the found minimum element with the first element*/
        swap(&arr[min_idx], &arr[i]);
    }
}

/* Function to print array */
void printArray(int *arr, int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code to test above functions
int main(void)
{
    int *arr;

    int size;
    printf("Enter the size of the array --->");
    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));

    printf("Enter %d numbers --->", size);
    for(int i = 0; i<size; i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);
    return 0;
}
