#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection sort algorithm
 *
 * @array: the array to sort
 * @size: of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
		int tmp;
		size_t low, i = 0, j;

		if (size < 2)
			return;

		while (i < size - 1)
		{
			low = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[low])
					low = j;
			}
			if (low != i)
			{
				tmp = array[i];
				array[i] = array[low];
				array[low] = tmp;
				print_array(array, size);
			}
			i++;
		}
}
