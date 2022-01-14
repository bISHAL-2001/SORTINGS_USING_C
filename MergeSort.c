/*Merge Sort is a Divide and Conquer algorithm.
 * It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
 * The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that
 *  arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. */
#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int left, int mid, int right) {
    int sizeOfLeftArray = mid - left + 1;
    int sizeOfRightArray = right - mid;

    int *leftArray = (int *) calloc(sizeOfLeftArray, sizeof(int *)), *rightArray = (int *) calloc(sizeOfRightArray,
                                                                                                  sizeof(int));

    /* Dividing Elements*/
    for (int i = 0; i < sizeOfLeftArray; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < sizeOfRightArray; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOfLArray = 0, indexOfRArray = 0, indexOfMergedArray = left;

    while (indexOfLArray < sizeOfLeftArray && indexOfRArray < sizeOfRightArray) {
        if (leftArray[indexOfLArray] <= rightArray[indexOfRArray]) {
            arr[indexOfMergedArray] = leftArray[indexOfLArray];
            indexOfLArray++;
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfRArray];
            indexOfRArray++;
        }
        indexOfMergedArray++;
    }

    while (indexOfLArray < sizeOfLeftArray) {
        arr[indexOfMergedArray] = leftArray[indexOfLArray];
        indexOfLArray++;
        indexOfMergedArray++;
    }
    while (indexOfRArray < sizeOfRightArray) {
        arr[indexOfMergedArray] = rightArray[indexOfRArray];
        indexOfRArray++;
        indexOfMergedArray++;
    }

}

void mergeSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
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
    int *arr, size;

    printf("Enter the size of the array:");
    scanf("%d", &size);
    arr = (int*)calloc(size, sizeof(int ));

    printf("Enter %d numbers:", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);


    printf("The Unsorted Array: ");
    print(arr, size);

    mergeSort(arr, 0, size-1);
    printf("The Sorted Array: ");
    print(arr, size);

    free(arr);
}

