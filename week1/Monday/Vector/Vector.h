#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <assert.h>

using namespace std;

size_t INITIAL_CAPACITY = 1;

template<class T>
class Vector
{
public:
	/**
		Constructs vector with initial size, capacity and buffer
	*/
	Vector():currentSize(0), v_capacity(INITIAL_CAPACITY), buffer(new T[INITIAL_CAPACITY]) {}


	/**
		Constructs vector with initial size 0
		@param v_capacity the given capacity of the vector
	*/
	Vector(size_t v_capacity):currentSize(0), v_capacity(v_capacity), buffer(new T[v_capacity]) {}


	/**
		Copies one vector into anonther(Copy constructor)
		@param other the vector to be copied
	*/
	Vector(const Vector<T>& other):currentSize(other.currentSize), v_capacity(other.v_capacity), buffer(new T[other.v_capacity])
	{
		for(size_t i = 0; i < currentSize; i++)
		{
			buffer[i] = other.buffer[i];
		}
	}


	/**
		Frees memory for buffer
	*/
	~Vector()
	{
		delete [] buffer;
	}	


	/**
		Adds item in the end of the vector
		@param item the item to be pushed
	*/
	void push(T item)
	{
		if(currentSize == v_capacity)
		{
			resize();
		}

		buffer[currentSize++] = item;
	}


	/**
		Removes the last element from the vector
	*/
	void pop()
	{
		assert(currentSize > 0);
		currentSize--;
	}


	/**
		Inserts element at given position
		@param pos the position the element must be inserted at
		@param item the item to be inserted
	*/
	void insert(size_t pos, T item)
	{
		assert(pos >= 0 && pos <= currentSize);
		if(pos == currentSize)
		{
			push(item); // If we ask to insert element at the last position, we push it
		}
		else
		{
			push(buffer[currentSize - 1]);
			for(size_t i = currentSize-1; i > pos; i--)
			{
				buffer[i] = buffer[i - 1];
			}
			buffer[pos] = item;
		}
	}


	/**
		Returns the current size of the vector
	*/
	size_t size()
	{
		return currentSize;
	}


	/**
		Returns the current size of the vector
	*/
	size_t capacity()
	{
		return v_capacity;
	}


	/**
		Prints the vector object
	*/
	void print() const
	{
		for(size_t i = 0; i < currentSize; i++)
		{
			cout << buffer[i] << " ";
		}
	}


	/**
		Overloaing assignment operator for the vector class
		@param other the vector we sign
	*/
	Vector<T>& operator =(const Vector<T>& other)
	{
		delete [] buffer;
		v_capacity = other.v_capacity;
		currentSize = other.currentSize;
		buffer = other.buffer;
		return *this;
	}

private:
	size_t v_capacity;
	size_t currentSize;
	T* buffer;


	/**
		Resizes the vector with twice the capacity
	*/
	void resize()
	{
		T* copyBuffer = new T[v_capacity * 2];
		for(size_t i = 0; i < currentSize; i++)
		{
			copyBuffer[i] = buffer[i];
		}
		delete [] buffer;
		v_capacity *= 2;
		buffer = copyBuffer;
	}
};

#endif