//Diameter of a binary tree

#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node *left, *right;
}node;

node* newnode(int data)
{
	node *tmp = new node;
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

int getint()
{
	int in;
	cin >> in;
	return in;
}

int max(int a, int b)	{ return a > b ? a : b; }

int height(node *root)
{
	if (root == NULL) return 0;
	if ( root->left == NULL )
		if (root->right == NULL)	return 0;
		else return height(root->right)+1;
	else if (root->right == NULL) return height(root->left)+1;
	else return max(height(root->right), height(root->left))+1;
}

int end2end(node *root)
{
	return height(root->left) + height(root->right) + 1;
}

int diameter(node *root)
{
	if (root == NULL)	return 1;
	else return(max(end2end(root), max(diameter(root->left), diameter(root->right))));
}

int main()
{
	node *root = newnode(getint());
	root->left = newnode(getint());
	root->right = newnode(getint());
	root->left->left = newnode(getint());
	root->right->right = newnode(getint());
	root->left->left->left = newnode(getint());
	root->left->left->right = newnode(getint());

	cout << diameter(root) << endl;

	while (1);
	return 1;
}