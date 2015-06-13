#include <iostream>

using namespace std;


void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void merge(int* arr, int* copyArr, int start, int mid, int end)
{
	int arrIndex = start;
	int left = start;
	int right = mid + 1;

	while (left <= mid && right <= end)
	{
		if (arr[left] <= arr[right]) copyArr[arrIndex++] = arr[left++];
		else copyArr[arrIndex++] = arr[right++];
	}

	if (left <= mid)
	{
		while (left <= mid) copyArr[arrIndex++] = arr[left++];
	}

	else while (right <= end) copyArr[arrIndex++] = arr[right++];

	for (int i = 0; i <= end; i++)
	{
		arr[i] = copyArr[i];
	}
}


void mergeSort(int* arr, int* copyArr, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;

		mergeSort(arr, copyArr, start, mid);
		mergeSort(arr, copyArr, mid + 1, end);

		merge(arr, copyArr, start, mid, end);
	}
}

int main()
{

	int arr[10] = { 5, 1, 9, 4, 7, 2, 3, 5, 6, 8 };
	int copyArr[10];

	mergeSort(arr, copyArr, 0, 9);

	print(arr, 10);

	system("pause");

	return 0;
}