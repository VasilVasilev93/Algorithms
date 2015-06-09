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

struct Stack
{
	int current_size;
	Queue* newQueue;

	Stack()
	{
		current_size = 0;
		newQueue = new Queue();
	}

	void push(int value)
	{
		newQueue->push(value);
		current_size++;
	}

	void pop()
	{
		Node* tempNode = newQueue->firstElem;

		while(tempNode->next->next)
		{
			tempNode = tempNode->next;
		}

		delete newQueue->lastElem;

		newQueue->lastElem = tempNode;
		newQueue->lastElem->next = NULL;

		current_size--;
	}

	int peek()
	{
		Node* tempNode = newQueue->firstElem;

		while(tempNode->next)
		{
			tempNode = tempNode->next;
		}
		
		return tempNode->value;
	}

	int size()
	{
		return current_size;
	}

	void print()
	{
		Node* tempNode = newQueue->firstElem;
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
	Stack test;

	test.push(5);
	test.push(6);
	test.push(7);
	test.push(8);
	test.push(9);
	test.push(10);
	test.push(11);

	test.pop();

	std::cout << test.peek() << std::endl;
	test.print();

	return 0;
}