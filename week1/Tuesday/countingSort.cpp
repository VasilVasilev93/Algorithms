#include <iostream>
#include <time.h>

using namespace std;


bool is_sorted(int* arr, int size)
{
	for(int i = 0; i < size-1; i++)
	{
		if(arr[i] > arr[i+1]) return false;
	}
	return true;
}

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void init_arr(int* arr, int size)
{
	for(int i = 0; i < size; i++) arr[i] = 0;
}

int find_max(int* arr, int size)
{
	int max = arr[0];
	for(int i = 1; i < size; i++)
	{
		if(arr[i] > max) max = arr[i];
	}
	return max;
}

void copy_arr(int* arr, int size, int* otherArr, int otherSize)
{
	if(size == otherSize)
	{
		for(int i = 0; i < size; i++) arr[i] = otherArr[i];
	}
}

void sum_arr_indexes(int* arr, int size)
{
	for(int i = 0; i < size-1; i++)
	{
		arr[i+1] += arr[i];
	}
}

void place_numbers(int* arr, int size, int* emptyArr, int* indexArr, int indexArrSize)
{
	for(int i = size - 1; i >= 0; i--)
	{
		emptyArr[indexArr[arr[i]]-1] = arr[i];
		indexArr[arr[i]]--;
	}
	
	copy_arr(arr, size, emptyArr, size);
}

void count(int* arr, int* copyArr, int arrSize, int copyArrSize)
{
	for(int i = 0; i < arrSize; i++)
	{
		copyArr[arr[i]]++;
	}

	sum_arr_indexes(copyArr, copyArrSize);
}

void countingSort(int* arr, int size)
{
	int copyArrSize = find_max(arr, size) + 1;
	int* copyArr = new int[copyArrSize];
	init_arr(copyArr, copyArrSize);

	count(arr, copyArr, size, copyArrSize);

	int* emptyArr = new int[size];
	init_arr(emptyArr, size);

	place_numbers(arr, size, emptyArr, copyArr, copyArrSize);
}

int main()
{
	int size = 100000000;
	int* arr = new int[size];

	for(int i = 0; i < size; i++) arr[i] = rand() % size;
	clock_t tStart = clock();

	countingSort(arr, size);

	cout << is_sorted(arr, size) << endl;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	
	//print(arr, size);

	return 0;
}