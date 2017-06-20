//Circuits
//Question: https://community.topcoder.com/stat?c=problem_statement&pm=1593&rd=4494

#include<iostream>
#define MAXSIZE 30
using namespace std;

int a[MAXSIZE][MAXSIZE], cost[MAXSIZE][MAXSIZE];
int n;

int dfs(int root)
{
	int i, flag = 0;

	for (i = 0; i < n;i++)
		if (a[root][i] == 1)
		{
			flag = 1;
			return cost[root][i] + dfs(i);
		}
	
	if (flag == 0)	return 0;
}

int main()
{
	int maxpath[MAXSIZE], max = 0, maxnode = -1;

	int i, j;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		a[i][j] = 0;
		cost[i][j] = 0;
	}

	cin >> n;

	i = 0;
	while (i < n)
	{
		cin >> j;
		if (j == -1)	i++;
		else
		{
			a[i][j] = 1;
		}
	}

	for (i = 0; i < n;i++)
		for (j = 0; j < n;j++)
			if (a[i][j] == 1)	cin >> cost[i][j];

	for (i = 0; i < n; i++)
	{
		maxpath[i] = dfs(i);
		if (maxpath[i]>max)
		{
			max = maxpath[i];
			maxnode = i;
		}
		cout << maxpath[i] << endl;
	}

	cout << "Critical path = " << max << " starting from node " << maxnode;
	while (1);
	return 0;
}