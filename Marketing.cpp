//Marketing
//Question: https://community.topcoder.com/stat?c=problem_statement&pm=1524&rd=4472

#include <iostream>

#define MAXSIZE 30
using namespace std;

bool visited[MAXSIZE];
bool value[MAXSIZE];

int n, a[MAXSIZE][MAXSIZE];

bool dfs(int root, bool target)
{
	bool ret = true;

	visited[root] = true;
	value[root] = target;

	int j;
	for (j = 0; j < n;j++)
		if (a[root][j] == 1)
			if (visited[j] && value[root] == value[j])
			{
				ret = false;
				return ret;
			}
			else if (!visited[j])
				ret = dfs(j, !target);

	return ret;
}

int main()
{
	int result, mult;
	bool disconnected[MAXSIZE];
	int i, j;
	for (i = 0; i < MAXSIZE; i++)
	{
		disconnected[i] = false;
		for (j = 0; j < MAXSIZE; j++)
			a[i][j] = 0;
	}

	cin >> n;

	result = 0, mult = 1;

	i = 0, j = 0;
	while (i < n)
	{
		cin >> j;
		if (j == -1)	i++;
		else
		{
			a[i][j] = 1;
			a[j][i] = 1;
		}
	}

	for (i = 0; i < n; i++)
	{
		int flag = 0;
		for (j = 0; j < n; j++)
			if (a[i][j] == 1)	flag = 1;
		if (flag == 0)	disconnected[i] = true;
	}

	for (i = 0; i < MAXSIZE; i++)
	{
		visited[i] = false;
	}

	for (i = 0; i < n;i++)
	{
		if (visited[i] == false)
			if(!disconnected[i])
			{
				if (!dfs(i,0))
				{
					result = 0;
					break;
				}
				result += 2;
			}
			else mult *= 2;
	}

	if (result != 0)	result *= mult;
	else if (mult != 1)	result = mult;
	cout << result << endl;
	while (1);
	return 0;
}