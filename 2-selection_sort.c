#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
unsigned int i, d, min_idx, temp;

for (i = 0; i < size - 1; i++)
{
min_idx = i;

for (d = i + 1; d < size; d++)
{
if (array[d] < array[min_idx])
{
min_idx = d;
}
}
if (min_idx != i)
{
/* Swap the elements */
temp = array[min_idx];
array[min_idx] = array[i];
array[i] = temp;
/* Print the array after each swap */
print_array(array, size);
}
}
}
