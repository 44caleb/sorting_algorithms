#include "sort.h"

/**
 * get_pivot - partitions array into 2 halves
 * @array: array of unsorted elements
 * @start: start of array
 * @end: end
 * @size: size
 * Return: index of midpoint after dividing
 */

size_t get_pivot(int *array, size_t start, size_t end, size_t size)
{
	size_t low = start;
	size_t high = end;
	size_t pivot = end;
	int tmp;

	while (low < high)
	{
		while (array[low] <= array[pivot] && low <= end)
		{
			low++;
		}
		while (array[high] > array[pivot] && high >= start)
		{
			high--;
		}
		if (low < high)
		{
			tmp = array[low];
			array[low] = array[high];
			array[high] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[pivot];
	array[pivot] = array[high];
	array[high] = tmp;
	print_array(array, size);

	return (high);
}

/**
 * sorter - recursively divides/sorts array
 * @array: array
 * @start: start
 * @end: end
 * @size: size
 * Returns: nothing
 */

void sorter(int *array, size_t start, size_t end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = get_pivot(array, start, end, size);

		sorter(array, start, pivot - 1, size);
		sorter(array, pivot + 1, end, size);
	}
}


/**
 * quick_sort - sorts array with quick sort
 * @array: array
 * @size: size
 * Returns: nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t start = 0;
	size_t end = size - 1;

	sorter(array, start, end, size);
}

