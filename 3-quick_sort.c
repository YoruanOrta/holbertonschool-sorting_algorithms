#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for QuickSort.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot after partitioning.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively applies QuickSort to sub-arrays.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * Quick Sort algorithm with Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quick_sort_recursive(array, 0, size - 1, size);
}
