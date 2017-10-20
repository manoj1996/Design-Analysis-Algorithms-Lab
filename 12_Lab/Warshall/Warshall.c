#include<stdio.h>
#include<stdlib.h>

void warshall(int** mat, int n);

int main()
{
	int n;
	int i, j;
	
	scanf("%d", &n);
	
	int** mat = malloc(sizeof(int*) * (n + 1));
	for(i = 1; i <= n; i++)
		mat[i] = malloc(sizeof(int) * (n + 1));
	
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &mat[i][j]);
	
	warshall(mat, n);
	
	printf("\n");
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
			printf("%d ", mat[i][j]);
		
		printf("\n");
	}
}

void warshall(int** mat, int n)
{
	int i, k, j;
	
	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <=n; j++)
				mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
}
