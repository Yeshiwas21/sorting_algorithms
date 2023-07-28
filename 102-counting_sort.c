#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *arr, int size)
{
int max_val = arr[0];
for (int i = 1; i < size; i++)
{
if (arr[i] > max_val)
	max_val = arr[i];
}
return max_val;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
int *count, *sorted_array, max_val, i;

if (array == NULL || size < 2)
	return;
sorted_array = malloc(sizeof(int) * size);
if (sorted_array == NULL)
	return;
max_val = get_max(array, size);
count = malloc(sizeof(int) * (max_val + 1));
if (count == NULL)
{
free(sorted_array);
return;
}
for (i = 0; i < (max_val + 1); i++)
	count[i] = 0;
for (i = 0; i < (int)size; i++)
	count[array[i]] += 1;
for (i = 1; i < (max_val + 1); i++)
	count[i] += count[i - 1];
print_array(count, max_val + 1);
for (i = size - 1; i >= 0; i--)
{
sorted_array[count[array[i]] - 1] = array[i];
count[array[i]] -= 1;
}
for (i = 0; i < (int)size; i++)
	array[i] = sorted_array[i];
free(sorted_array);
free(count);
}
