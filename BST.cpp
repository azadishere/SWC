#include<iostream>
#include<conio.h>
using namespace std;

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
}node;

class bst
{

public:
	bst() { root = NULL; }
	void printbst(node *subtree);
	void deletebst(node *subtree);
	node *insertdata(node *root, int data);
	node *deletedata(node *root, int data);
	node *returnroot()	{ return root; }
private:
	node *root;
	node *newnode(int data);
};

node* bst::newnode(int data)
{
	node *tmp = new node;
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void bst::printbst(node *subtree)
{
	if (subtree)
	{
		printbst(subtree->left);
		cout << subtree->data << " ";
		printbst(subtree->right);
	}

}

void bst::deletebst(node *subtree)
{
	if (subtree)
	{
		deletebst(subtree->left);
		deletebst(subtree->right);
		delete subtree;

	}
}

node* bst::insertdata(node *root, int data = 0)
{
	if (this->root == NULL)
	{
		this->root = newnode(data);
		return root;
	}
	if (root == NULL)	return newnode(data);

	if (data <= root->data)		root->left = insertdata(root->left, data);
	else	root->right = insertdata(root->right, data);

	return root;
}

node* bst::deletedata(node *root, int data)
{
	if (root == NULL)	return root;
	if (root->data <= data)
	{
		deletebst(root->left);
		root->left = NULL;
		node *tmp = root;
		root = root->right;
		if (root == NULL) this->root = root;
		delete tmp;
		return deletedata(root, data);
	}
	else
	{
		this->root = root;
		return root;
	}
}

int main()
{
	bst tree;
	int input;
	cin >> input;
	tree.insertdata(tree.returnroot(), input);
	cin >> input;
	tree.insertdata(tree.returnroot(), input);
	tree.printbst(tree.returnroot());
	cout << endl;
	cin >> input;
	tree.insertdata(tree.returnroot(), input);
	cin >> input;
	tree.insertdata(tree.returnroot(), input);
	cin >> input;
	tree.insertdata(tree.returnroot(), input);
	cin >> input;
	tree.insertdata(tree.returnroot(), input);
	tree.printbst(tree.returnroot());
	cout << endl;
	cin >> input;
	tree.deletedata(tree.returnroot(), input);
	tree.printbst(tree.returnroot());
	cout << endl;
	tree.deletebst(tree.returnroot());
	//while (1);
	//system("Pause");
	getch();
return 0;
}