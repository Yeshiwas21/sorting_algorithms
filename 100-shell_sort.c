#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort.
 * @array: The unsorted array.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
int tmp;
size_t gap, i, j;

if (!array || size < 2)
	return;
gap = 1;
while (gap < size / 3)
	gap = gap * 3 + 1;
while (gap > 0)
{
for (i = gap; i < size; i++)
{
tmp = array[i];
for (j = i; j >= gap && tmp < array[j - gap]; j -= gap)
	array[j] = array[j - gap];
array[j] = tmp;
}
gap /= 3;
print_array(array, size);
}
}

