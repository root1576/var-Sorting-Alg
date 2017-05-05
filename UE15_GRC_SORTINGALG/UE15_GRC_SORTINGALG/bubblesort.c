#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void bubbleSort(int* pointer_array, int array_length)
{
	int array_changed = 0;
	do
	{
		array_changed = 0;
		for (int sort_pos = 0; sort_pos < array_length - 1; sort_pos++)
		{
			if (pointer_array[sort_pos] > pointer_array[sort_pos + 1])
			{
				int tmp = pointer_array[sort_pos];
				pointer_array[sort_pos] = pointer_array[sort_pos + 1];
				pointer_array[sort_pos + 1] = tmp;
				array_changed++;
			}
		}
	} while (array_changed != 0);
	printf("\n\nSorted array: \n");
	printTable(pointer_array, array_length);
}