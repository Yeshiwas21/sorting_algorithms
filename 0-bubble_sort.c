#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using Bubble Sort.
 * @arr: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *arr, size_t size)
{
    unsigned int i, j;
    int tmp;

    if (size < 2 || arr == NULL)
        return;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                /* Swap the elements */
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                /* Print the array after each swap */
                print_array(arr, size);
            }
        }
    }
}