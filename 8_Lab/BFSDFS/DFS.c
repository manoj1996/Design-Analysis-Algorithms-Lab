#include<stdio.h>
#include<stdlib.h>

int numComponents(int** a, int order);
void dfs(int** a, int* mark, int order, int j);

int main()
{
	int tc, order;
	int i, j, k;
	int** arr;
	int* res;
	
	scanf("%d", &tc);
	res = malloc(sizeof(int) * tc);
	
	
	for(k = 0; k < tc; k++)
	{
		scanf("%d", &order);
		
		arr = malloc(sizeof(int*) * (order + 1));
		for(i = 1; i <= order; i++)
			arr[i] = malloc(sizeof(int) * (order + 1));
		
		for(i = 1; i <= order; i++)
			for(j = 1; j <= order; j++)
				scanf("%d", &arr[i][j]);
		
		res[k] = numComponents(arr, order);
	}
	
	for(i = 0; i < tc; i++)
		printf("%d\n", res[i]);
	
	return 0;
}

/*
Algorithm DFS(G)
Mark each vertex in v with 0
count ← 0
for each vertex v in V
if (v is marked with 0)
dfs(v)
Procedure dfs(v)
count ← count + 1
Mark v with count
for each vertex w in V adjacent to v
if (w is marked with 0)
dfs(w)
*/

int numComponents(int** a, int order)
{
	int i, j;
	int count = 0;

	int* mark = malloc(sizeof(int) * (order + 1));
	for(i = 1; i <= order; i++)
		mark[i] = 0;
	
	/*
	for(i = 1; i <= order; i++)
	{
		for(j = 1; j <= order; j++)
			printf("%d \t", a[i][j]);
		printf("\n");
	}
	*/

	for(j = 1; j <= order; j++)
	{
		if(mark[j] == 0)
		{
			dfs(a, mark, order, j);
			count ++;
		}
	}
	return count;
}

void dfs(int** a, int* mark, int order, int j)
{
	int i;
	
	mark[j] = 1;
	
	for(i = 1; i <= order; i++)
		if(a[j][i] == 1)
			if(mark[i] == 0)
				dfs(a, mark, order, i);
}
