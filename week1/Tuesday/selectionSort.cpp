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

void selectionSort(int* arr, int size)
{
	int min;

	for(int i = 0; i < size; i++)
	{
		min = arr[i];
		for(int j = i; j < size; j++)
		{
			if(arr[j] < min)
			{
				swapf(arr[i], arr[j]);
				min = arr[i];
			}
		}
	}
}

int main()
{
	int size = 10;
	int arr[10] = {4,8,2,1,7,5,11,15,9,6};
	
	selectionSort(arr, size);

	printf(arr,size);

    return 0;
}
