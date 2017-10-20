#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m, n, i, j;
	printf("Enter the order of the matrix (the number of rows followed ny the number of columns)\n");
	scanf("%d%d", &m, &n);
	int arr[m][n];
	
	for(i = 0; i < m; i ++)
		for(j = 0; j < n; j ++)
			scanf("%d", &arr[i][j]);
	
	printf("The original matrix is : \n");
	
	for(i = 0; i < m; i ++)
	{
		for(j = 0; j < n; j ++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
	
	return 0;
}
