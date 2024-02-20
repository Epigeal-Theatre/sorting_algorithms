#include "sort.h"

/**
 * swap - this function will swap two ints
 *
 * @a: int a placeholder
 *
 * @b: int b placeholder
 *
 * Return: (void) Swaped int
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Partitions an array and using pivot
 *
 * @array: the array
 *
 * @low: placeholder for low int
 *
 * @high: placeholder for high int
 *
 * @size: the size of array (size_t)
 *
 * Return: return the index of pivot as an (int)
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}
/**
 * lomuto_qsort - Sorting an array Recursively
 *
 * @array: the rray to be sorted
 *
 * @low: lowest value of the array
 *
 * @high: the highest value of the array
 *
 * @size: the ize of The Array
 *
 * Return: return void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_qsort(array, low, i - 1, size);
		lomuto_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - Quick sorts Algorithms using lomuto partitioning
 *
 * @array: the array to sort
 *
 * @size: the size of The Array
 *
 * Return: Sorted Array (void)
 */

void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
