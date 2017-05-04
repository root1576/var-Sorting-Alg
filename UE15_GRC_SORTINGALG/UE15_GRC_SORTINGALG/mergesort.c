#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "mergesort.h"

//mergeSortRecursive is the recursive version of mergesort
//pointer_array <-- pointer on first element of array
//array_length <-- real size of array (not n-1)
//tableprint == 1 if function is supposed to print the array
void mergeSortRecursive(int* pointer_array, int array_length,int tablePrint)
{
	if (array_length > 2)
	{
		int* tmp_pointer_array = NULL;
		int offset_left = 0, offset_right = 0;

		//recursion (and split array) if array_length is bigger than 2
		mergeSortRecursive(pointer_array, array_length / 2 + array_length % 2, 0);
		mergeSortRecursive(&(pointer_array[array_length / 2 + array_length % 2]), array_length / 2, 0);

		//allocate memory for sorting array
		tmp_pointer_array = malloc((array_length / 2 + array_length % 2)*sizeof(int));//for memory optimaztion after recursion

		//exception if malloc couldn't allocate memory for sorting
		if (tmp_pointer_array == NULL)
		{
			printf("Memory error: Couldn't allocate memory for sorting! (Mergesort)");
			exit(1);
		}

		//for (int i = 0; i < array_length / 2 + array_length % 2; i++)//copying half of the array into other array used for sorting -> no element gets overwritten
				

		for (int sort_pos = 0; sort_pos < array_length; sort_pos++)
		{
			//saving data in 2nd array -> no data gets overwritten
			if (sort_pos < array_length / 2 + array_length % 2)
				tmp_pointer_array[sort_pos] = pointer_array[sort_pos];

			if (((tmp_pointer_array[offset_left] <= pointer_array[array_length / 2 + array_length % 2 + offset_right]) || offset_right >= array_length / 2) && (offset_left<array_length / 2 + array_length % 2))
				pointer_array[sort_pos] = tmp_pointer_array[offset_left++];
			else
				pointer_array[sort_pos] = pointer_array[array_length / 2 + array_length % 2+offset_right++];
		}
		free(tmp_pointer_array);
	}
	else
	{
		if(array_length>1)//to prevent accessing not assigned memory
			if (pointer_array[0] > pointer_array[1])//if numb1 bigger than numb2 -> swap
			{
				int tmp = pointer_array[0];
				pointer_array[0] = pointer_array[1];
				pointer_array[1] = tmp;
			}
		return;
	}

	if (tablePrint == 1)
		printTable(pointer_array, array_length);

	return;
}






//*********************************************
//*********SPAGHETTICODE**INCOMING*************
//*********************************************

//YOU SHOULDN'T LOOK AT THIS!!!!!

//DON'T!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//IF YOU LOOK FURTHER IT MAY DAMAGE YOUR MENTAL HEALTH

//YOU HAVE BEEN WARNED


void mergeSortSpaghetti(int* pointer_array, int array_length)
{
	int* tmp_pointer = NULL;
	int* sort_this = pointer_array;
	int* sort_to = malloc(array_length * sizeof(int));

	int offset_left = 0, offset_right = 0;

	for (int cart_size = 2; cart_size/2 <= array_length; cart_size *= 2)
	{
		for (int cart_pos = 0; cart_pos < array_length; cart_pos += cart_size)
		{
			int cart_size_left, cart_size_right;
			int remainder = (array_length) % cart_size;

			if (cart_pos + cart_size > array_length && cart_pos != array_length)
			{
				if (remainder < cart_size / 2)
					continue;
				else
				{
					cart_size_left = cart_size / 2;
					cart_size_right = remainder - cart_size_left;
				}
			}
			else
			{
				cart_size_left = cart_size / 2;
				cart_size_right = cart_size / 2;
			}

			offset_left = 0;
			offset_right = 0;

			for (int inner_cart_pos = 0; inner_cart_pos < (cart_size_left+cart_size_right); inner_cart_pos++)
			{
				if (((sort_this[cart_pos + offset_left] <= sort_this[cart_pos + cart_size_left + offset_right]) || offset_right >= cart_size_right) && (offset_left < cart_size_left))
					sort_to[cart_pos + inner_cart_pos] = sort_this[cart_pos + offset_left++];
				else
					sort_to[cart_pos + inner_cart_pos] = sort_this[cart_pos + offset_right++ + cart_size_left];
			}
				
		}


		//swaping sorting arrays
		tmp_pointer = sort_this;
		sort_this = sort_to;
		sort_to = tmp_pointer;
	}
	//printf("Sorted array!\n");
	//printTable(sort_this, array_length);
	return;
}