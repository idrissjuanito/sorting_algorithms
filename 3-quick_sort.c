#include "sort.h"


void swap(int *array, size_t size, size_t i, size_t j);

/**
 * partition_sch - sorts an array using the quick sort algorithm
 *
 * @array: the list to sort
 * @size: size of the array
 * @low: lower bound of partition
 * @high: higher bound of the partition
 *
 * Return: void
 */
void partition_sch(int *array, size_t size, size_t low, size_t high)
{
	size_t i = low, j, pivot;

	if (high <= low)
		return;

	pivot = high - 1;
	for (j = low; j < pivot; j++)
	{
		if (array[j] < array[pivot])
		{
			swap(array, size, i, j);
			i++;
		}
	}
	swap(array, size, i, pivot);
	partition_sch(array, size, 0, i);
	partition_sch(array, size, i + 1, high);
}

/**
 * quick_sort - sorts an array using quick sort algorithm
 *
 * @size: of the array to sort
 * @array: to sort
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	partition_sch(array, size, 0, size);
}

/**
 * swap - swaps values of two array indexes
 *
 * @array: the array
 * @size: the size of the array
 * @i: index one to swap
 * @j: index two to swap
 *
 * Return: void
 */
void swap(int *array, size_t size, size_t i, size_t j)
{
	int tmp;

	if (i == j)
		return;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}
