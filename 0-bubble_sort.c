#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order with Bubble sort
 * @array: Pointer to the first element of the array
 * @size: The size of the array
 *
 * Description: This function sorts the array using the Bubble sort algorithm
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	int swapped;

	for (size_t i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
		break;
	}
}
