#include "sort.h"

/**
 * swap - function to swap passed parameters
 * @a: passed param as a pointer to the element to swap
 * @b: passed param as a pointer to the element to swap
 *
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * l_part - partiion the array using lomuto
 * @array: list of array to be sorted
 * @low: passed param as starting index
 * @high: passed param as last index
 * @size: passed param as size of the array of the list
 *
 * Return: index
 */
int l_part(int *array, int low, int high, size_t size)
{
	int p = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < p)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_s_h - to sort the array
 * @array: passed param as a list of arrays to be sorted
 * @low: passed param as starting index
 * @high: passed param as last index
 * @size: passed param as size of the list of arrays
 *
 * Return: nothing
 */
void quick_s_h(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p_index = l_part(array, low, high, size);

		quick_s_h(array, low, p_index - 1, size);
		quick_s_h(array, p_index + 1, high, size);
	}
}

/**
 * quick_sort: sort the arrays using quick sort
 * @array: list of arrays to be sorted
 * @size: list of the list of arrays
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		quick_s_h(array, 0, size - 1, size);
	}
}
