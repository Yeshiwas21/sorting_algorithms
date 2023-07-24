#include "sort.h"

/**
*bubble_sort - sorts array of integers in ascending order
*@array: array to be sorted
*@size: size of array
*Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
unsigned int i, d, tmp;

if (size < 2)
{
return;
}

for (i = 0; i < size - 1; i++)
{
for (d = 0; d < size - i - 1; d++)
{
if (array[d] > array[d + 1])
{
tmp = array[d];
array[d] = array[d + 1];
array[d + 1] = tmp;
print_array(array, size);
}
}
}
}