#include "sort.h"
/**
 * bubble_sort - sorts array with bubble sort
 * @array: array of elements
 * @size: size
 * Returns: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, nsize = size;
	int tmp, arranged = 0;

	while (arranged == 0)
	{
		arranged = 1;

		if (nsize == 0)
		{
			break;
		}
		for (i = 0; i < nsize - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				arranged = 0;
			}
		}
		nsize--;
	}
}
