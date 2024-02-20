#include "sort.h"
#include <stdio.h>

/**
* bitonic_compare - sort the values in a sub-array WRT Bitonic sort algo
*
* @up: The direction of sorting
*
* @array: sub-array to sort
*
* @size: size of the sub-array
*
* Return: void
*/
void bitonic_compare(char up, int *array, size_t size)
{
	size_t i, dist;
	int swap;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == up)
		{
			swap = array[i];
			array[i] = array[i + dist];
			array[i + dist] = swap;
		}
	}
}

/**
* bitonic_merge - a recursive function that merges two sub-arrays
*
* @up: the direction of sorting
*
* @array: the sub-array to sort
*
* @size: the size of the sub-array
*
* Return: return void
*/
void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
* bit_sort - Bitonic sort algorithm recursive
*
* @up: the direction of sorting
*
* @array: the sub-array to sort
*
* @size: the size of the sub-array
*
* @t: the total size of the original array
*
* Return: void
*/

void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitonic_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
* bitonic_sort - this function sorts an array of integers in ascending
* ...order using the Bitonic sort algorithm
*
* @array: the array to sort
*
* @size: the size of the array
*
* Return: void
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
