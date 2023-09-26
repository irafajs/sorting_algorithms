#include "sort.h"

/**
 * selection_sort - sort list using selection method
 * @array: passed param as an list of arrays to be sorted
 * @size: passed param as the size of the list of arrays
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_ind;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min_ind = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_ind])
			{
				min_ind = j;
			}
		}
		if (min_ind != i)
		{
			temp = array[i];
			array[i] = array[min_ind];
			array[min_ind] = temp;
			print_array(array, size);
		}
	}
}
