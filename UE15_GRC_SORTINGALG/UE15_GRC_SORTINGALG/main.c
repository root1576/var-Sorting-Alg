#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertsort.h"
#include "main.h"

#undef RNG //if defined array will be generated with random size and filled with random numbers


typedef enum {
	INSERTIONSORT,
	MERGESORT
}SORTINGALG;


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

	printf("Generate random array: \n\n");
	printf("\nSize of array: %d\n", size_array);
	printf("\nUnsorted array:\n");

	printTable(sort_array, size_array);

	sort(INSERTIONSORT, sort_array, size_array);

	free(sort_array);
#else //RNG

	int sort_array[] = { 92,4,6,7,252,4,83,5,49,10,134,156,7,29};

	printf("\nUnsorted array:\n");

	printTable(sort_array, sizeof(sort_array)/sizeof(int));

	sort(INSERTIONSORT, sort_array,sizeof(sort_array)/sizeof(int));

#endif //RNG
	getchar();
}



#ifdef RNG

//creates an array with random size and fills it with random numbers
//returns length of the array and saves random numbers to pointer array
int randomNumArray(int** pointer_array)
{
	int size_of_array;
	time_t t;

	srand((unsigned int)time(&t));//def. RNG seed

	size_of_array = rand() % 256;//def. random size of array // 256 def. maxsize of array
	//printf("Size of array: %d", size_of_array);

	*pointer_array = (int*)malloc((size_of_array) * sizeof(int));//allocate memory for array

	for (int i = 0; i < size_of_array; i++)
		(*pointer_array)[i] = rand() % 1000;//generate random numbers and store in array

	return size_of_array;//return size of array
}
#endif // RNG

//Executes and takes the time for all implemented algorithms
//actual implemented algorithms: Insertionsort
void sort(SORTINGALG sortingalg,int* pointer_array, int length)
{
	int start_time = clock();

	switch (sortingalg)
	{
		case INSERTIONSORT:
			printf("\nSorting array with insertionsort!\n");
			insertSort(pointer_array,length);
			break;
		case MERGESORT:
			printf("\nMERGESORT NOT YET IMPLEMENTED!\n"); //Mergsort implementation in next version!
			/*printf("\nSorting array with mergesort!\n");
			mergeSortFast(pointer_array, length);*/
			break;
		default:
			printf("\nDEFAULTSORT ALSO NOT YET IMPLEMENTED!\n");
			break;
	}
	printf("\n\nTime used: %fs\nThis time is not representative, because the printing of the table fakes the result!", ((double)clock() - start_time) / CLOCKS_PER_SEC);
}

//prints the array \n after 8 numb
void printTable(int* array_pointer, int length)
{

	for (int i = 0; i < length; i++)
	{
		if (i % 8 == 0 && i != 0) // After every 8 numbers breakline
			printf("\n");
		printf("%4d;", array_pointer[i]);
	}
	printf("\n");
}