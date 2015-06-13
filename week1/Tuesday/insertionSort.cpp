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

void insertionSort(int* arr, int size)
{
	int temp;
	for(int i = 0; i < size-1; i++)
	{
		if(arr[i] > arr[i+1])
		{
			int k = i;
			temp = arr[i+1];
			while(temp < arr[k] && k >= 0)
			{
				arr[k+1] = arr[k];
				k--;
			}
			arr[k+1] = temp;
		}
	}
}

int main()
{
	int size = 10;
	int arr[10] = {4,8,2,1,7,5,11,15,9,6};
	
	insertionSort(arr, size);

	printf(arr,size);

    return 0;
}
