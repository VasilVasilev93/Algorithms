#include <iostream>

int CAPACITY = 2;

struct Vector
{
	int *arr;
	int current_size;
	int arrCapacity;
	
	Vector()
	{
		current_size = 0;
		arrCapacity = CAPACITY;
		arr = new int[arrCapacity];
	}

	void insert(int index, int value)
	{
		if(index >= current_size) return;

		if(current_size == arrCapacity)
		{
			int* copyArr = new int[2*arrCapacity];
			for(int i = 0; i < arrCapacity; i++)
			{
				copyArr[i] = arr[i];
			}
			arrCapacity *= 2;
			delete [] arr;
			arr = copyArr;
		}

		else
		{
			for(int i = 0; i < current_size - index; i++)
			{
				arr[current_size - i] = arr[current_size - i - 1];
			}
		}

		arr[index] = value;
		current_size++;
	};

	void add(int value)
	{
		if(current_size == arrCapacity)
		{
			int* copyArr = new int[2*arrCapacity];
			for(int i = 0; i < arrCapacity; i++)
			{
				copyArr[i] = arr[i];
			}
			arrCapacity *= 2;
			delete [] arr;
			arr = copyArr;
		}
		
		arr[current_size++] = value;
	}

	int getValue(int index)
	{
		if(index > current_size || index < 0) return 0;

		return arr[index];
	}

	void remove(int index)
	{
		if(index >= current_size || index < 0) return;

		for(int i = 0; i < current_size - 1 - index; i++)
		{
			arr[index + i] = arr[index + i + 1];
		}
		current_size--;
	}

	void pop()
	{
		current_size--;
	}

	int size()
	{
		return current_size;
	}

	int capacity()
	{
		return arrCapacity;
	}

	void print()
	{
		for(int i = 0; i < current_size; i++)
		{
			std::cout << arr[i];
		}

		std::cout << std::endl;
	}

};


int main()
{
	Vector test;
	test.add(5);
	test.add(3);
	test.add(6);
	test.add(8);
	test.add(7);
	test.insert(0, 1);
	test.pop();
	test.remove(1);
	test.print();

	return 0;
}