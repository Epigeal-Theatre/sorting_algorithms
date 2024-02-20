#include "sort.h"
#include <stdio.h>


/**
 * merge -  func will sort array using merge sort
 *
 * @array: array if integers
 *
 * @size: the size of the array
 *
 * @l: pointer to the left array
 *
 * @r: pointer to the right array
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_left);
	printf("[right]: ");
	print_array(r, size_right);

	while (i < size_left && j < size_right)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}

	while (i < size_left)
		array[k++] = l[i++];

	while (j < size_right)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - func sorts an array of ints in ascending order using the
 *.... Merge sort algorithm
 *
 * @array: pointer to an array
 *
 * @size: size of array
 **/

void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	mid = size / 2;

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
