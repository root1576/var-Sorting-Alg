#include <stdio.h>
#include <stdlib.h>

#include "insertsort.h"
#include "main.h"

//Sorting algorithm
void insertSort(int* array_pointer, int length)
{
	for (int sort_pos = 1; sort_pos < length; sort_pos++)//searching number out of order
	{
		for (int insert_pos = 0; (array_pointer[sort_pos - insert_pos] < array_pointer[sort_pos - insert_pos - 1]) && (insert_pos < sort_pos); insert_pos++)//swaping element with elemnt in pos-1 until in correct position
		{
			int tmp_swap = array_pointer[sort_pos - insert_pos - 1]; //swap current number with last number
			array_pointer[sort_pos - insert_pos - 1] = array_pointer[sort_pos - insert_pos];
			array_pointer[sort_pos - insert_pos] = tmp_swap;
		}
	}
	printf("\nSorted Array: \n");
	printTable(array_pointer, length);
}
 
