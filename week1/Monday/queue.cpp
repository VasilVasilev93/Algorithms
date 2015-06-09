#include <iostream>

struct Node
{
	int value;
	Node *next;

	Node(int value)
	{
		this->value = value;
		this->next = NULL;
	}

};

struct Queue
{
	int current_size;
	Node* firstElem;
	Node* lastElem;
	Queue()
	{
		lastElem = new Node(0);
		firstElem = new Node(0);
		this->current_size = 0;
	}

	void push(int value)
	{
		Node* newNode = new Node(value);

		if(current_size == 0)
		{
			firstElem = newNode;
			lastElem = firstElem;
		}
		else
		{
			lastElem->next = newNode;
			lastElem = newNode;
		}
		current_size++;
	}

	void pop()
	{
		if(current_size == 0)return;
		Node* tempNode = firstElem->next;
		//firstElem->next = NULL;
		delete firstElem;
		firstElem = tempNode;
		//firstElem = firstElem->next;
		current_size--;
	}

	int peek()
	{
		return firstElem->value;
	}

	int size()
	{
		return current_size;
	}

	void printList()
	{
		Node* tempNode = firstElem;
		while(tempNode->next)
		{
			std::cout << tempNode->value;
			tempNode = tempNode->next;
		}
		std::cout << tempNode->value;
		delete tempNode;
	}
};


int main()
{
	Queue test;
	test.push(5);
	test.push(6);
	test.push(7);
	test.push(9);
	test.pop();
	test.printList();
	std::cout << std::endl;
	std::cout << test.peek();

	return 0;
}