#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


// Define structure node 
struct node
{
	int value;
	struct node *left;
	struct node *right;
}*root;

// Define class Btree 
class Btree
{
public:

	void insert(node *, node *);
	void preorder(node *);
	void search(node *, int value);
	int depth(node *);

	Btree()
	{
		root = NULL;
	}
};

int main()
{
	int number, option;
	Btree tree;

	bool loop = true;
	while(loop)
	{

		// Take option from user for specified Tree traversal and perform the function

		cout << "Select Function of to perform on a tree" << endl;
		cout << "1. Insert element to the tree " << endl;
		cout << "2. Pre-order traversal of the tree "<< endl;
		cout << "3. Search node in the tree  " <<endl;
		cout << "4. Height of the Tree " << endl;
		cout << "5. Exit program " << endl;
		cout << "Enter option number :  ";
		cin >> option;



		switch(option)
		{
			case 1:
			cout << "Enter number of elements to be inserted :  ";
			int numloop;
			cin >> numloop;
			for (int i=0; i<numloop; i++)
			{
				cout << "Enter value of element to be inserted :  ";
				int eleme;
				cin >> eleme;
				node* newNode = new node();
				newNode->value = eleme;
				tree.insert(root, newNode);

			}
			cout << "Elements inserted " << endl;
			cout << endl;
			break;

			case 2:
			cout << endl ;
			tree.preorder(root);
			cout << endl ;
			cout << endl;
			break;

			case 3:
			cout << "Enter element to be searched : ";
			int elementsearch;
			cin >> elementsearch;
			cout << endl;
			tree.search(root, elementsearch);
			cout << endl;
			break;


			case 4:
			cout << endl;
			cout << "Height of tree is  :  " << tree.depth(root) << endl;
			cout << endl;
			break;

			case 5:
			loop = false;
			break;

			default:
			cout << endl;
			cout << "Not valid option "<< endl;
			cout << endl;

		}


}
	return 0;
}


// function to insert the node in tree 
void Btree::insert(node *tree, node *newNode)
{

	// Check if tree is empty
	if (root == NULL) 
	{
		root = new node;
		root->value = newNode->value;
		root->left = NULL;
		root->right = NULL;
		return;
	}

	// Check if value exists in tree

	if (tree->value == newNode->value)
	{
		cout << "Element already exist in the tree" << endl;
		return;
	}

	// Find the position where the node is to be inserted

	if (tree->value > newNode->value)
	{
		if (tree->left != NULL)
		{
			insert(tree->left, newNode);
		}
		else
		{
			tree->left = newNode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			return;
		}
	}
	else
	{
		if (tree->right != NULL)
		{
			insert(tree->right, newNode);
		}
		else
		{
			tree->right = newNode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			return;
		}
	}
}


// Function to perform pre-order traversal 
void Btree::preorder(node *treeNode)
{
	//Check if tree is empty
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (treeNode != NULL)
	{
		cout << treeNode->value << "   ";
		preorder(treeNode->left);
		preorder(treeNode->right);
	}

}


// Function to calculate height / depth of 
int Btree::depth(node* tree)
{
	// Check if tree is empty
	if (root == NULL)
	{ 
		cout << "Tree is empty" << endl;
		return 0;
	}
	
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		int lTreeDepth = depth(tree->left);
		int rTreeDepth = depth(tree->right);

		if (lTreeDepth > rTreeDepth)
			return (lTreeDepth + 1);
		else
			return (rTreeDepth + 1);
	}
}


// Fucntion to search for element in tree 
void Btree::search(node *tree, int value)
{
	node *ptrTemp, *ptrPrevious;
	// check if Tree is empty
	if (root == NULL)
	{
		cout << "No nodes present in tree. Tree is empty" << endl;
		return;
	}

	//Check if value is at root
	if (value == root->value)
	{
		cout << "Node found" << endl;
		return;
	}

	if (value < root->value)
		ptrTemp = root->left;
	else
		ptrTemp = root->right;
	
	ptrPrevious = root;

	// Traverse the tree to locate node
	while (ptrTemp != NULL)
	{
		if (value == ptrTemp->value)
		{
			cout << "Node found" << endl;
			return;
		}
		ptrPrevious = ptrTemp;
		if (value < ptrTemp->value)
			ptrTemp = ptrTemp->left;
		else
			ptrTemp = ptrTemp->right;
	}

	// If node not in tree
	cout << "Item not present in the tree" << endl;
}
