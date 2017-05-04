#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertsort.h"
#include "mergesort.h"
#include "main.h"

#undef RNG //if defined array will be generated with random size and filled with random numbers


typedef enum {
	INSERTIONSORT,
	MERGESORTREC,
	MERGESORTSPAG,
}SORTINGALG;

int sort_array[] = {
#include "zrnd_1000000.txt"
};

//Fct.prototype ***********************************************************************
void sort(SORTINGALG sortingalg, int* pointer_array, int length);

#ifdef RNG
int randomNumArray(int** pointer);
#endif //RNG

void main(void)
{
#ifdef RNG
	int* sort_array = NULL;
	int size_array = randomNumArray(&sort_array);

	//exception if malloc couldn't allocate memory for sorting

	if (sort_array == NULL)
	{
		printf("Memory error: Couldn't allocate memory for sorting! (Mergesort)");
		exit(1);
	}

	printf("Generate random array: \n\n");
	printf("\nSize of array: %d\n", size_array);
	printf("\nUnsorted array:\n");

	//printTable(sort_array, size_array);
	//getchar();
	//sort(MERGESORTREC, sort_array, size_array);

	sort(MERGESORTSPAG, sort_array, size_array);

	free(sort_array);
#else //RNG


	printf("\nUnsorted array: %d\n",sizeof(sort_array)/sizeof(int));

	//printTable(sort_array, sizeof(sort_array)/sizeof(int));

	sort(MERGESORTSPAG, sort_array,sizeof(sort_array)/sizeof(int));

#endif //RNG
	getchar();
	return;
}



#ifdef RNG
//creates an array with random size and fills it with random numbers
//returns length of the array and saves random numbers to pointer array
int randomNumArray(int** pointer_array)
{
	int size_of_array;
	time_t t; //to define the seed of the rng

	srand((unsigned int)time(&t));//def. RNG seed

	size_of_array = 1000000;//rand() % 256;//def. random size of array // 256 def. maxsize of array
	//printf("Size of array: %d", size_of_array);

	*pointer_array = (int*)malloc((size_of_array) * sizeof(int));//allocate memory for array

	for (int i = 0; i < size_of_array; i++)
		(*pointer_array)[i] = rand() % 10000;//generate random numbers and store in array

	return size_of_array;
}
#endif // RNG

//Executes and takes the time for all implemented algorithms
//actual implemented algorithms: Insertionsort
void sort(SORTINGALG sortingalg,int* pointer_array, int length)
{
	int start_time = clock();//saves the starttime

	switch (sortingalg)
	{
		case INSERTIONSORT:
			printf("\nSorting array with insertionsort!\n");
			insertSort(pointer_array,length);
			break;
		case MERGESORTREC:
			printf("\nSorting array with mergesort (recursive algorithm)!\n");
			mergeSortRecursive(pointer_array, length, 0);
			break;
		case MERGESORTSPAG:
			printf("\nSorting array with mergesort (spagetti algorithm)!\n");
			mergeSortSpaghetti(pointer_array, length);
			break;			
		default:
			printf("\nDEFAULTSORT ALSO NOT YET IMPLEMENTED!\n");
			break;
	}
	printf("\n\nTime used: %fs\nThis time is not representative,\nbecause the printing of the table fakes the result!", ((double)clock() - start_time) / CLOCKS_PER_SEC);
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