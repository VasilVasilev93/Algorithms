#include <iostream>

using namespace std;

class Node
{

private:
	int data;
	Node* left;
	Node* right;

public:
	friend class BST;

	Node(int data):data(data), left(NULL), right(NULL) {}

	void insert_node(Node* newNode)
	{
		if(newNode->data < data)
		{
			if (left == NULL) left = newNode;
			else left->insert_node(newNode);
		}
		
		else if (data < newNode->data)
		{
			if (right == NULL) right = newNode;
			else right->insert_node(newNode);
		}
	}
};

class BST
{
private:
	Node* root;

public:
	

	BST():root(NULL){}

	void insert(int data)
	{
		Node* newNode = new Node(data);
		if (root == NULL) root = newNode;
		else
			root->insert_node(newNode);
	}

	bool isBST(Node* root) const
	{
		if (root == NULL) return true;
		if ((root->left == NULL || root->data >= root->left->data)
			&& (root->right == NULL || root->data < root->right->data)
			&& isBST(root->left)
			&& isBST(root->right))
			return true;
		else return false;
	}

	Node* getRoot()
	{
		return root;
	}

	void changeRoot(int data)
	{
		root->data = data;
	}
};

int main()
{
	BST t;
	
	t.insert(5);
	t.insert(6);
	t.insert(1);
	t.insert(2);
	t.insert(10);
	t.insert(8);
	t.insert(12);
	t.insert(4);

	cout << "Binary tree before change of root: " << t.isBST(t.getRoot()) << "\n";

	t.changeRoot(6);

	cout << "Binary tree after change of root: " << t.isBST(t.getRoot()) << "\n";

	
	return 0;
};