#include <iostream>

using namespace std;


void extendArr(int* &arr, int currentSize, int &size)
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


void keepRule(int* arr, int lastCopy, int first, int last)
{
	while(lastCopy/2 >= first)
	{
		if(arr[lastCopy/2] < arr[lastCopy])
		{
			swap(arr[lastCopy/2], arr[lastCopy]);
		}
		lastCopy --;
	}

	int firstCopy = first;
	while(firstCopy < last || firstCopy*2 <= last)
	{
		if(firstCopy*2 + 1 <= last && (arr[firstCopy] < arr[firstCopy*2 + 1]))
		{
			swap(arr[firstCopy], arr[firstCopy*2 + 1]);
		}
		else if(firstCopy*2 <= last && (arr[firstCopy] < arr[firstCopy*2]))
		{
			swap(arr[firstCopy], arr[firstCopy*2]);
		}

		firstCopy++;
	}
}


bool is_sorted(int* arr, int size)
{
	for(int i = 1; i < size; i++)
	{
		if(arr[i] < arr[i+1]) return false;
	}
	return true;
}

struct Heap
{
	int *arr;
	int last;
	int first;
	int size;
	int sortArrIndex;
	int* sortedArr;

	Heap()
	{
		size = 2;
		arr = new int[size];
		first = 1;
		last = 1;
		sortArrIndex = first;
		sortedArr = new int[size];
	}

	void print(int* arr)
	{
		for(int i = 1; i < last; i++) cout << arr[i] << " ";
	}

	void insert(int value)
	{
		if(last == size) 
		{
			extendArr(this->arr, last, size);
			delete [] sortedArr;
			sortedArr = new int[size];
		}

		//int lastCopy = last;
		arr[last++] = value;
		if(last - 1 == 1) return;
		keepRule(arr, last - 1, first, last);
	}

	void removeMax()
	{
		if(first > last)
		{
			last--;
			delete [] arr;
			arr = sortedArr;
			return;
		}
		sortedArr[sortArrIndex++] = arr[first];
		
		for(int i = 1; i < last; i++)
		{
			arr[i] = arr[i+1];
		}
		last--;

	}

	void sort()
	{
		last--;
		while(first <= last + 1)
		{
			removeMax();
			keepRule(arr, last - 1, first, last);
		}
		last = sortArrIndex;
		//delete [] sortedArr;
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
	for(int i = 0; i < 100000; i++)
	{
		test.insert(rand() % 1000);
	}

	test.sort();

	cout << is_sorted(test.arr, test.last);

	
	return 0;
}