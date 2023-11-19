#include "sort.h"

/**
 * quick_sort - sorts an array with quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int wall, pivot;

	if (array && size > 1)
	{
		wall = 0;
		pivot = (size - 1);

		quick_s(wall, pivot, array, size);
	}
}
/**
 * quick_s - recursively (divide & conquer) partition and repeat
 * @wall: beginning of sub array to sort
 * @pivot: end of sub array to sort and pivot point
 * @array: the beginning of the array, for printing purposes
 * @size: size of entire array for printing
 */
void quick_s(int wall, int pivot, int *array, size_t size)
{
	int first_wall, second_wall, n_pivot;

	if (wall < pivot)
	{
		second_wall = partition(wall, pivot, array, size);

		first_wall = wall;
		n_pivot = second_wall - 1;

		if (first_wall != n_pivot && second_wall != pivot)
			n_pivot--;

		quick_s(first_wall, n_pivot, array, size);
		quick_s(second_wall, pivot, array, size);
	}
}
/**
 * partition - divides and sorts an array into sub arrays semi-sorted
 * @wall: beginning of array partition
 * @pivot: end of array to partition
 * @array: the beginning of the array, for printing purposes
 * @size: size of entire array for printing
 *
 * Return: the new wall barrier
 */
int partition(int wall, int pivot, int *array, size_t size)
{
	int i;

	i = wall;

	while (i != pivot)
	{
		if (array[i] < array[pivot])
		{
			if (i != wall)
			{
				swap_int(array + i, array + wall);
				print_array(array, size);
			}
			i++;
			wall++;
		}
		else
			i++;
	}
	if (wall != pivot)
	{
		if (array[wall] > array[pivot])
		{
			swap_int(array + pivot, array + wall);
			print_array(array, size);
		}
		wall++;
	}
	return (wall);
}

/**
  * swap_int - swap two integers
  * @first_int: integer 1
  * @second_int: interger 2
  */
void swap_int(int *first_int, int *second_int)
{
	int temp;

	temp = *first_int;

	*first_int = *second_int;
	*second_int = temp;
}
