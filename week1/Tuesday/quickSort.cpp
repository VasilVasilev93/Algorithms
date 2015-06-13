#include <iostream>

using namespace std;

void printf(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(int* arr, int start, int end)
{
	if(start > end) return 0;
	int pivot = arr[end];
	int partitionIndex = start;

	for(int i = start; i < end; i++)
	{
		if(arr[i] <= pivot)
		{
			swap(arr[i], arr[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(arr[partitionIndex], arr[end]);

	return partitionIndex;
}

void quickSort(int* arr, int start, int end)
{
	int partitionIndex = partition(arr, start, end);
	if(partitionIndex < 2) return;
	quickSort(arr, start, partitionIndex - 1);
	quickSort(arr, partitionIndex + 1, end);
}


int main()
{
	int size = 10;
	int arr[10] = {4,8,2,1,7,5,11,15,9,6};

	quickSort(arr, 0, size-1);
	
	printf(arr,size);

    return 0;
}