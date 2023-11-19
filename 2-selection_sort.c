#include "sort.h"
/**
  * selection_sort - sorts and array of integers in ascending order
  * @array: the array being sorted
  * @size: size of the array
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *tmp;

	tmp = NULL;

	for (i = 0; array && i < size - 1; i++)
	{
		tmp = NULL;
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				if (tmp && array[j] < *tmp)
				{
					tmp = &array[j];
				}
				else if (!tmp)
				{
					tmp = &array[j];
				}
			}
		}
		if (tmp)
		{
			swap_int(tmp, &array[i]);
			print_array(array, size);
		}
	}
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
