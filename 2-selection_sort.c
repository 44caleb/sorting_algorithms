#include "sort.h"

/**
 * selection_sort - sorts with selection sort
 *@array: array of elements
 *@size: size
 *Returns: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t start = 0;
	size_t i;
	int smallest, j, tmp;

	while (start < size)
	{
		smallest = array[start];
		j = start;

		for (i = start; i < size; i++)
		{
			if (smallest > array[i])
			{
				smallest = array[i];
				j = i; /* store index of new smallest */
			}
		}

		/* swap numbers */
		tmp = array[start];
		array[start] = smallest;
		array[j] = tmp;
		print_array(array, size);
		start++; /* increment start of array */
	}
}
