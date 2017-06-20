//Connected Intervals
//Question: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/connected-intervals-1/

#include<iostream>

using namespace std;

long n, **a;
bool **graph, *visited;
long visitcount;

void boolreset(long n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		visited[i] = false;
		for (j = 0; j < n; j++)
			graph[i][j] = false;
	}
	visitcount = n;
}

void dfs(int root = 0)
{
	int i;

	visited[root] = true;
	visitcount--;
	for (i = 0; i < n; i++)
	{
		if (graph[root][i] && !visited[i])
			dfs(i);
	}
}

int main()
{
	long m;
	long i, u, v;
	long result;
	cin >> n >> m;

	visited = new bool[n];
	graph = new bool*[n];
	for (i = 0; i < n; i++)
		graph[i] = new bool[n];

	a = new long*[m];
	for (i = 0; i < m; i++)
	{
		a[i] = new long[2];
		cin >> u >> v;
		a[i][0] = u-1;
		a[i][1] = v-1;
	}

	result = 0;
	long l, r;
	for (l = 0; l < m;l++)
	for (r = l + n - 2; r < m; r++)
	{
		boolreset(n);
		for (i = l; i <= r; i++)
		{
			graph[a[i][0]][a[i][1]] = true;
			graph[a[i][1]][a[i][0]] = true;
		}
		dfs();
		if (visitcount == 0)
		{
			result += m - r;
			break;
		}
	}

	cout << result;
	while (1);

	delete visited;
	for (i = 0; i < n; i++)		delete graph[i];
	delete graph;
	for (i = 0; i < m; i++)		delete a[i];
	delete a;

	return 0;
}