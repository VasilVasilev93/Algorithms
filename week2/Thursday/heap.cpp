#include <iostream>
#include <time.h>

using namespace std;


void extendArr(int* &arr, int &size)
	{

			int* copyArr = new int[2*size];
			for(int i = 0; i < size; i++)
			{
				copyArr[i] = arr[i];
			}
			size *= 2;
			delete [] arr;

			arr = copyArr;
	}

bool is_sorted(int* arr, int size)
{
	for(int i = 1; i < size; i++)
	{
		if(arr[i] < arr[i+1]) return false;
	}
	return true;
}

void insertHelper(int* arr, int first, int last)
{
	int copyLast = last;
	while(copyLast > first)
		{
			if(arr[copyLast] > arr[copyLast/2])
			{
				swap(arr[copyLast], arr[copyLast/2]);
				copyLast /= 2;
			}
			else
			{
				break;
			}
		}
}

void removeMaxHelper(int* arr, int first, int last)
{
	int copyFirst = first;
	while(copyFirst*2 <= last)
		{
			if(copyFirst*2 + 1 <= last)
			{
				if(arr[copyFirst] < arr[copyFirst*2] && arr[copyFirst*2] >= arr[copyFirst*2 + 1])
				{
					swap(arr[copyFirst], arr[copyFirst*2]);
					copyFirst *= 2;
					continue;
				}
				else if(arr[copyFirst] < arr[copyFirst*2 + 1])
				{
					swap(arr[copyFirst], arr[copyFirst*2 + 1]);
					copyFirst = copyFirst*2 + 1;
					continue;
				}
			}
			else
			{
				if(arr[copyFirst] < arr[copyFirst*2])
				{
					swap(arr[copyFirst], arr[copyFirst*2]);
					copyFirst *= 2;
					continue;
				}
			}
			break;
		}
}

struct Heap
{
	int *arr;
	int last;
	int first;
	int size;

	Heap()
	{
		size = 2;
		arr = new int[size];
		first = 1;
		last = 1;
	}

	void print(int* arr)
	{
		for(int i = 1; i < last; i++) cout << arr[i] << " ";
	}

	void insert(int value)
	{
		if(last == size)
		{
			extendArr(arr, size);
		}

		arr[last++] = value;
		if(last > 2)
		{
			insertHelper(arr, first, last-1);
		}
	}

	void removeMax()
	{
		swap(arr[first], arr[last-1]);
		last--;
		removeMaxHelper(arr, first, last-1);
	}
	
	void heapSort()
	{
		int* sortedArr = new int[size];
		int copyLast = last;
		for(int i = 1; i < copyLast; i++)
		{
			sortedArr[i] = getMax();
			removeMax();
		}
		last = copyLast;
		delete [] arr;
		arr = sortedArr;
	}

	int getMax()
	{
		return this->arr[first];
	}
};


int main()
{
	int size = 10;

	Heap test = Heap();
	for(int i = 0; i < 1000000; i++)
	{
		test.insert(rand() % 32768);
	}

	clock_t tStart = clock();

	test.heapSort();

	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cout << endl;

	cout << is_sorted(test.arr, test.last);

	
	return 0;
}