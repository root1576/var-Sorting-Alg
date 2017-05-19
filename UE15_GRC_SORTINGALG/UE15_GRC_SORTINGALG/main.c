#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "insertsort.h"
#include "mergesort.h"
#include "bubblesort.h";
#include "main.h"

#undef RNG //if defined array will be generated with random size and filled with random numbers


typedef enum {
	INSERTIONSORT,
	BUBBLESORT,
	MERGESORTREC,
	//MERGESORTSPAG,
}SORTINGALG;

static const char *SORTINGALGORITHMS[] = { "INSERTSORT","BUBBLESORT","MERGESORTREC" };



//Fct.prototype ***********************************************************************
void sort(SORTINGALG sortingalg, int* pointer_array, int length);
int checkArray(int* tmp_sorted_array, int* check_array, int array_length);
void sortTest(void(*fct)(SORTINGALG, int*, int), SORTINGALG sortingalg, int* array_template, int array_length,int* check_array);

void main(void)
{
	int ARRAY_TEMPLATE[] = {
#include "zrnd_1000000.txt" 
	};
	int* check_array = malloc(sizeof(ARRAY_TEMPLATE));
	memcpy(check_array, ARRAY_TEMPLATE, sizeof(ARRAY_TEMPLATE));
	sort(INSERTIONSORT, check_array, sizeof(ARRAY_TEMPLATE) / sizeof(int));
	
	sortTest(sort, BUBBLESORT, ARRAY_TEMPLATE, sizeof(ARRAY_TEMPLATE) / sizeof(int), check_array);
}

//Executes and takes the time for all implemented algorithms
//actual implemented algorithms: Insertionsort, bubblesort, mergesort
void sort(SORTINGALG sortingalg,int* pointer_array, int length)
{
	switch (sortingalg)
	{
		case INSERTIONSORT:
			printf("\nSorting array with insertionsort!\n");
			insertSort(pointer_array,length);
			break;
		case BUBBLESORT:
			printf("\nSorting array with bubblesort!\n");
			bubbleSort(pointer_array, length);
		case MERGESORTREC:
			printf("\nSorting array with mergesort (recursive algorithm)!\n");
			mergeSortRecursive(pointer_array, length, 0);
			break;
		/*case MERGESORTSPAG:
			printf("\nSorting array with mergesort (spagetti algorithm)!\n");
			mergeSortSpaghetti(pointer_array, length);
			break;*/
		default:
			printf("\nDEFAULTSORT ALSO NOT YET IMPLEMENTED!\n");
			break;
	}
}

void sortTest(void (*fct)(SORTINGALG,int*,int),SORTINGALG sortingalg,int* array_template, int array_length,int* check_array)
{
	int* array_to_sort = malloc(array_length * sizeof(int));
	memcpy(array_to_sort,array_template,array_length*sizeof(int));

	fct(sortingalg, array_to_sort, array_length);

	if (checkArray(array_to_sort, checkArray, array_length) == 0)
		printf("PASS");
	else
		printf("FAIL");
	return;
}

//compares tmp_sorted_array with the check_array
//if arrays are not the same return -1 else 0
int checkArray(int* tmp_sorted_array, int* check_array, int array_length)
{
	for (int pos = 0; pos < array_length; pos++)
		if (tmp_sorted_array[pos] != check_array[pos]) return -1;
	return 0;
}

//prints the array \n after n numb
void printTable(int* array_pointer, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i % 16 == 0 && i != 0) // After every 8 numbers breakline
			printf("\n");
		printf("%4d;", array_pointer[i]);
	}
	printf("\n");
}