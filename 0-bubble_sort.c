#include "sort.h"

/**
  * bubble_sort - sorts an array of ints in ascending order
  * @array: the array being sorted
  * @size: the size of the array
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	bool flag;

	n = size;
	i = 0;
	flag = 1;

	if (array == NULL || size < 2)
		return;

	while (flag == 1)
	{
		flag = 0;
		for (; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_int(array + i, array + i +1);
				print_array(array, size);
				flag = 1;
			}
		}
		n--;
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

	*second_int = *second_int;
	*second_int = temp;
}
