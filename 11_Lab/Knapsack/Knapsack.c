#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int knapsack(int** matrix, int i, int j, int weights[], int values[]);
int max(int a, int b);

int main()
{
	int items;
	int* weights;
	int* values;
	int capacity;
	int** matrix;
	int i, j;
	
	scanf("%d", &items);
	
	weights = malloc(sizeof(int) * (items + 1));
	values = malloc(sizeof(int) * (items + 1));
	
	for(i = 1; i <= items; i++)
		scanf("%d", &weights[i]);
		
	for(i = 1; i <= items; i++)
		scanf("%d", &values[i]);
	
	scanf("%d", &capacity);
	
	matrix = malloc(sizeof(int*) * (items + 1));
	for(i = 0; i <= items; i++)		//VIMP => i <= items since the number of rows is one more than the number of items
		matrix[i] = malloc(sizeof(int) * (capacity + 1));

	for(i = 0; i <= items; i++)
		for(j = 0; j <= capacity; j++)
		{
			if(i == 0 || j == 0)
				matrix[i][j] = 0;
			else
				matrix[i][j] = -1;
		}

	/*
	for(i = 0; i <= items; i++)
	{
		for(j = 0; j <= capacity; j++)
			printf("%d   ", matrix[i][j]);
		printf("\n");
	}	
	*/

	printf("%d\n", knapsack(matrix, items, capacity, weights, values));
	
	return 0;
}

int knapsack(int** matrix, int i, int j, int weights[], int values[])
{
	int value;

	if(matrix[i][j] < 0)
	{
		if(j < weights[i])
			value = knapsack(matrix, i - 1, j, weights, values);
		else
			value = max(knapsack(matrix, i - 1, j, weights, values), (values[i] + knapsack(matrix, i - 1, j - weights[i], weights, values)));
		
		matrix[i][j] = value;
	}
	
	return matrix[i][j];
}

int max(int a, int b)
{
	if(a >= b)
		return a;
	return b;
}
