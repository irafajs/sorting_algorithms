#include "sort.h"

/**
 * counting_sort - sort the list using counting method
 * @array: passed param as a list
 * @size: passed param as size of the list
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i;
	int *counting_array;
	int j, index;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		counting_array[array[i]]++;
	}
	for (j = 0; j <= max; j++)
	{
		printf("%d", counting_array[j]);
		if (j < max)
		{
			printf(", ");
		}
	}
	printf("\n");
	index = 0;
	for (j = 0; j <= max; j++)
	{
		while (counting_array[j] > 0)
		{
			array[index++] = j;
			counting_array[j]--;
		}
	}
	free(counting_array);
}
