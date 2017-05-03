#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "mergesort.h"


void mergeSortFast(int* pointer_array, int array_length,int tablePrint)
{
	if (array_length > 2)
	{
		
		mergeSortFast(pointer_array, array_length / 2 + array_length % 2,0);
		mergeSortFast(&(pointer_array[array_length / 2 + array_length % 2]), array_length / 2,0);

		int* tmp_pointer_array = malloc((array_length / 2 + array_length % 2)*sizeof(int));//for memory optimaztion after recursion
		int offset_left = 0, offset_right = 0;//also

		for (int i = 0; i < array_length / 2 + array_length % 2; i++)//copying half of the array into other array
				tmp_pointer_array[i] = pointer_array[i];

		for (int inner_cart_pos = 0; inner_cart_pos < array_length; inner_cart_pos++)
		{
			if (((tmp_pointer_array[offset_left] <= pointer_array[array_length / 2 + array_length % 2 + offset_right]) || offset_right >= array_length / 2) && (offset_left<array_length / 2 + array_length % 2))
			{
				pointer_array[inner_cart_pos] = tmp_pointer_array[offset_left];
				offset_left++;
			}
			else
			{
					pointer_array[inner_cart_pos] = pointer_array[array_length / 2 + array_length % 2+offset_right];
					offset_right++;
			}
		}
		free(tmp_pointer_array);
	}
	else
	{
			if ((pointer_array[0] > pointer_array[1])&&array_length>1)
			{
				int tmp = pointer_array[0];
				pointer_array[0] = pointer_array[1];
				pointer_array[1] = tmp;
				return;
			}
			return;
	}
	if (tablePrint == 1)
		printTable(pointer_array, array_length);
	return;
}