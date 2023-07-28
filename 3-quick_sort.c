#include "sort.h"

/**
 * myswap - Swaps two values in an array.
 *
 * @array: The array to be sorted.
 * @first: Index of the first element to swap.
 * @second: Index of the second element to swap.
 * @size: Size of the array.
 *
 * Return: No Return.
 */
void myswap(int *array, int first, int second, int size)
{
int tmp;

if (array[first] != array[second])
{
tmp = array[first];
array[first] = array[second];
array[second] = tmp;
print_array(array, size);
}
}

/**
 * partition - Chooses a pivot and partitions the array around it.
 *
 * @array: The array to be sorted.
 * @left: The leftmost index of the partition.
 * @right: The rightmost index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the new pivot.
 */
int partition(int *array, int left, int right, size_t size)
{
int i = left, j, pivot = array[right];

for (j = left; j <= right; j++)
{
if (array[j] < pivot)
{
myswap(array, i, j, size);
i++;
}
}
myswap(array, i, right, size);
return (i);
}

/**
 * myquicksort - Recursive function to perform the Quick Sort.
 *
 * @array: The array to be sorted.
 * @left: The leftmost index of the array or partition.
 * @right: The rightmost index of the array or partition.
 * @size: Size of the array.
 *
 * Return: No Return.
 */
void myquicksort(int *array, int left, int right, size_t size)
{
int pivot;

if (left < right)
{
pivot = partition(array, left, right, size);
myquicksort(array, left, pivot - 1, size);
myquicksort(array, pivot + 1, right, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 *
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Return: No Return.
 */
void quick_sort(int *array, size_t size)
{
if (size < 2 || array == NULL)
	return;
myquicksort(array, 0, size - 1, size);
}

