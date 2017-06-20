//Maximal Connection
//Question: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/maximal-connection/

#include<iostream>
#define MAXSIZE 100000
using namespace std;

bool *isspl, **graph, *visited;
long n;

long dfs(long root)
{
	long val = 0;

	if (isspl[root])	val++;
	visited[root] = true;

	for (long i = 0; i < n;i++)
		if (graph[root][i] == 1 && !visited[i])
			val += dfs(i);
	
	return val;
}

void clearvisited()
{
	for (long i = 0; i < n; i++)
		visited[i] = false;
}

int main()
{
	long m, x;
	long i, j, u, v;

	cin >> n >> m >> x;

	isspl = new bool[n];
	for (i = 0; i < n; i++)	isspl[i] = false;

	for (i = 0; i < m; i++)
	{
		cin >> j;
		isspl[j - 1] = true;
	}

	graph = new bool*[n];
	for (i = 0; i < n; i++)
	{
		graph[i] = new bool[n];
		for (j = 0; j < n; j++)
			graph[i][j] = 0;
	}

	for (i = 0; i < x; i++)
	{
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	long *conpow = new long[n];
	long sum = 0;
	visited = new bool[n];
	for (i = 0; i < n; i++)
	{
		clearvisited();
		conpow[i] = dfs(i);
		sum += conpow[i];
	}

	cout << sum << endl;

	while (1);
	delete isspl;
	for (i = 0; i < n; i++)	delete graph[i];
	delete graph;
	delete conpow;
	return 0;
}