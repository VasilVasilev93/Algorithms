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

void swapf(int& first, int& other)
{
	int temp = first;
	first = other;
	other = temp;
}

void bubbleSort(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size-1; j++)
		{
			if(arr[j] > arr[j+1]) swapf(arr[j], arr[j+1]);
		}
	}
}

int main()
{
	int size = 10;
	int arr[10] = {4,8,2,1,7,5,11,15,9,6};
	
	bubbleSort(arr, size);

	printf(arr,size);

    return 0;
}
