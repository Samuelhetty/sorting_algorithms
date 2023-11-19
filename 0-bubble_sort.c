#include "sort.h"

/**
  * bubble_sort - sorts an array of ints in ascending order
  * @array: the array being sorted
  * @size: the size of the array
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int *a, *b, flag;

	n = size;
	i = 0;
	flag = 0;

	while (i < n && array)
	{
		if (i == n - 1)
		{
			i = 0;
			flag = 0;
			n--;
		}
		a = &array[i], b = &array[i + 1];
		if (*a > *b)
		{
			swap_int(a, b);
			print_array(array, size);
			flag = 1;
		}
		i++;
		if (i == n - 1 && flag == 0)
			break;
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
