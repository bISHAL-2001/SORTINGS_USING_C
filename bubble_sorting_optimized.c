//Average and worst case will have a complexity of O(n^2)
//Best case when the array is sorted O(n)


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Swapping occurs*/
void swap(int i, int j, int *arr)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*Bubble Sorting occurs*/
void sort(int *arr, int size)
{

    //This counter reduces the complexity, stopping the inner loop to check for swaps//
    bool flag;
    for(int i = 0; i < size - 1; i++)
    {
        flag = false;
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(j, j+1, arr);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}

/*Printing the array*/
void print(int *arr, int size)
{
    printf("Output:\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

/*Driver Code*/
int main(void) {
    int size;
    printf("Enter the number of elements you want to enter --->");
    scanf("%d", &size); //Size of the array

    /*Allocation of the memory*/
    int *arr;
    arr = (int*)calloc(size, sizeof(int));

    /*Input of elements*/
    printf("Enter %d numbers --->", size);
    for(int i = 0; i<size; i++)
        scanf("%d", &arr[i]);

    /*Arranging of elements*/
    sort(arr, size);

    /* Printing the array*/
    print(arr, size);

    /* Freeing the allocated memory*/
    free(arr);
    return 0;
}
