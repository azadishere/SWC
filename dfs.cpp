#include<iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node *next;
}node;

class stack
{
private:
	node *top;
	int count;
public:
	stack()
	{
		top = NULL;
		count = -1;
	}
	void push(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if (top == NULL)	top = temp;
		else
		{
			temp->next = top;
			top = temp; 
			count++;
		}
	}
	int pop()
	{
		if (top == NULL)		return -1;
		node *tmp = top;
		int val = top->data;
		top = top->next;
		delete tmp;
		count--;
		return val;
	}
	bool isempty()
	{
		return top == NULL;
	}
	void display()
	{
		node *tmp = top;
		while (1)
		{
			if (tmp == NULL)
			{
				cout << "NULL";
				break;
			}
			cout << tmp->data<<"->";
			tmp = tmp->next;
		}
		cout << endl;
	}
};

class graph
{
private:
	int n;
	int **A;
	int *value;
public:
	graph(int size = 2)
	{
		if (size < 2) n = 2;
		else n = size;

		A = new int*[n];
		value = new int[n];
		for (int i = 0; i < n; i++)
		{
			A[i] = new int[n];
			//value[i] = new int;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				A[i][j] = 0;
			cin>>value[i];
		}
	}
	~graph()
	{
		for (int i = 0; i < n; i++)
			delete A[i];
		delete A;
		delete value;
	}
	void addEdge(int x, int y)
	{
		A[x][y] = A[y][x] = 1;
	}
	bool isconnected(int x, int y)
	{
		return A[x][y] == 1;
	}

	int DFS(int required, int start = 0)
	{
		stack s;
		bool visited[100];
		for (int i = 0; i < n; i++)	visited[i] = false;
		if (value[start] == required)	return start;
		s.push(start);
		s.display();
		visited[start] = true;
		int vertex,i;
		while (!s.isempty())
		{
			vertex = s.pop();
			cout << "Pop " <<vertex << endl;
			s.display();
			if (value[vertex] == required)	return vertex;
			for(int i = n-1;i>=0;i-- )
				if (isconnected(i, vertex) && !visited[i])
				{
					s.push(i);
					cout <<"Push "<< i << endl;
					s.display();
					visited[i] = true;
				}
		}
		return -1;
	}
};

int main()
{
	int size, find, vertex;
	cin >> size;
	graph g(size);

	g.addEdge(0, 1);
	g.addEdge(0, 2); 
	g.addEdge(1, 3);
	g.addEdge(2, 4); 
	g.addEdge(3, 6); 
	g.addEdge(4, 7);
	g.addEdge(4, 8); 
	g.addEdge(3, 5);
	cin >> find;
	vertex = g.DFS(find);
	if (vertex>=0)	cout << "Value found at vertex " <<vertex<< endl;
	else cout << "Value not found";
	while (1);
	return 1;
}
