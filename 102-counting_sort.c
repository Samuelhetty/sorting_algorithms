#include "sort.h"

/**
  * counting_sort - sorts an array of ints in ascending order w/counting sort
  * @array: the array that is being sorted
  * @size: the size of the array beigin sorted
  */
void counting_sort(int *array, size_t size)
{
	int i, max, end, value_placed;
	int *n_array, *end_ar;

	end = 0;
	if (array && size > 1)
	{
		max = array[0];
		for (i = 0; i < (int)size; i++)
			if (array[i] > max)
				max = array[i];
		n_array = calloc(sizeof(int *), max + 1);
		for (i = 0; i < (int)size; i++)
		{
			value_placed = array[i];
			n_array[value_placed]++;
		}
		for (i = 0; i < max + 1; i++)
		{
			if (n_array[i] != 0)
			{
				end += n_array[i];
				n_array[i] = end;
			}
			else
				n_array[i] += end;
		}
		print_array(n_array, max + 1);
		end_ar = malloc(sizeof(int *) * size);
		for (i = 0; i < (int)size; i++)
		{
			value_placed = array[i];
			end = n_array[value_placed];
			end_ar[--end] = value_placed;
			n_array[value_placed]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = end_ar[i];
		free(n_array);
		free(end_ar);
	}
}
