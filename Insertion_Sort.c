/*
 *Insertion sort is a simple sorting algorithm where the array is virtually split into a sorted and an unsorted part.
 *Values from the unsorted part are picked and placed at the correct position in the sorted part.
 *Algorithm
To sort an array of size n in ascending order:
1: Iterate from arr[1] to arr[n] over the array.
2: Compare the current element (key) to its predecessor.
3: If the key element is smaller than its predecessor, compare it to the elements before.
    Move the greater elements one position up to make space for the swapped element.

Time Complexity: O(n^2)
Auxiliary Space: O(1)
Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
Algorithmic Paradigm: Incremental Approach
 */

// C program for insertion sort
#include <stdio.h>
#include <stdlib.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
    int *arr;
    int size;
    printf("Enter the size of the array -->");
    scanf("%d", &size);
    arr = (int*)calloc(size, sizeof(int));

    printf("Enter %d numbers -->", size);
    for(int i =0; i<size; i++)
        scanf("%d", &arr[i]);

    insertionSort(arr, size);
    printf("The sorted array -->");
    printArray(arr, size);
    arr = NULL;
    free(arr);
    return 0;
}
