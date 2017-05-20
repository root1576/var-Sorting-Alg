#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "insertsort.h"
#include "mergesort.h"
#include "bubblesort.h"
#include "main.h"

//to add sorting algorithm: add sortingalg. in enum SORTINGALG and the name in SORTINGALGORITHMS
//and in sort() -> switch

typedef enum {
	INSERTIONSORT,
	BUBBLESORT,
	MERGESORTREC,
	//MERGESORTSPAG,
}SORTINGALG;

SORTINGALG alg[] = { INSERTIONSORT, MERGESORTREC, BUBBLESORT , MERGESORTREC };//order after which the algorithms get executed

static const char *SORTINGALGORITHMS[] = { "INSERTSORT","BUBBLESORT","MERGESORTREC" };


//Fct.prototype ***********************************************************************
void sort(SORTINGALG sortingalg, int* pointer_array, int length);
int checkArray(int* tmp_sorted_array, int* check_array, int array_length);
void sortTest(void(*fct)(SORTINGALG, int*, int), SORTINGALG sortingalg, int* array_template, int array_length,int* check_array);

void main(void)
{
	int ARRAY_TEMPLATE[] = { 
		27446,	23805, 15890,6729,24370,15350,15006,31101,24393,3548,19629,12623,24084,19954,18756,1840,4966,7376,13931,26308,16944,32439,
		24626,11323,5537,21538,16118,2082,22929,16541,4833,31115,4639,29658,22704,9930,13977,2306,31673,22386,5021,28745,26924,19072
	};	

	int* check_array = malloc(sizeof(ARRAY_TEMPLATE));//creating array to check the following sorting arrays
	memcpy(check_array, ARRAY_TEMPLATE, sizeof(ARRAY_TEMPLATE));

	sort(INSERTIONSORT, check_array, sizeof(ARRAY_TEMPLATE) / sizeof(int));
	
	for(int i = 0; i < sizeof(alg)/sizeof(SORTINGALG);i++)
		sortTest(sort, alg[i], ARRAY_TEMPLATE, sizeof(ARRAY_TEMPLATE) / sizeof(int), check_array);
	getchar();
}

//Executes and takes the time for all implemented algorithms
//actual implemented algorithms: Insertionsort, bubblesort, mergesort
void sort(SORTINGALG sortingalg,int* pointer_array, int length)
{
	switch (sortingalg)
	{
		case INSERTIONSORT:
			//printf("\nSorting array with insertionsort!\n");
			insertSort(pointer_array,length);
			break;
		case BUBBLESORT:
			//printf("\nSorting array with bubblesort!\n");
			bubbleSort(pointer_array, length);
		case MERGESORTREC:
			//printf("\nSorting array with mergesort (recursive algorithm)!\n");
			mergeSortRecursive(pointer_array, length, 0);
			break;
		default:
			printf("\nError: Sortingalgorithm not yet implemented!\n");
			break;
	}
}


//only for testing
void sortTest(void (*fct)(SORTINGALG,int*,int),SORTINGALG sortingalg,int* array_template, int array_length,int* check_array)
{
	int time_start, time_end;
	int* array_to_sort = malloc(array_length * sizeof(int));

	memcpy(array_to_sort,array_template,array_length*sizeof(int));//copy template

	printf("\nSorting array with the %s algorithm:",SORTINGALGORITHMS[sortingalg]);
	
	time_start = clock();//start timer
	fct(sortingalg, array_to_sort, array_length);
	time_end = clock();//stop timer

	printf("\nTime used to sort %d elements: %fs\n", array_length, (time_end - time_start) / (double)CLOCKS_PER_SEC);

	printf("Result: ");
	if (checkArray(array_to_sort, check_array, array_length) == 0)
		printf("PASS\n");
	else
		printf("FAIL\n");
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