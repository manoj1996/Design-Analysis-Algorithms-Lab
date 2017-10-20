#include<stdio.h>
#include<stdlib.h>

struct Element
{
	int val;
	char dir;
};

int greatestMobElem(struct Element permArr[], int n);
void changeDir(struct Element permArr[], int p, int i);
int calcCost(int n, int** arr, struct Element permArr[], int minCost);

int main()
{
	int n;
	int i, j;
	int minCost;
	
	scanf("%d", &n);
	int** arr = malloc(sizeof(int*)*(n + 1));		//int arr[n + 1][n + 1];
	for(i = 1; i <= n; i++)
		arr[i] = malloc(sizeof(int) * (n + 1));
	
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= n; j ++)
			scanf("%d", &arr[i][j]);
	/*Printing the matrix
	for(i = 1;i <= n; i ++)
	{
		for(j = 1; j <= n; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
	*/
	
	struct Element permArr[n];	//contains the numbers from 1 upto the input number
	
	for(j = 1; j <= n; j ++)
	{
		permArr[j].val = j;
		permArr[j].dir = 'l';
	}
	
	int m = greatestMobElem(permArr, n);
	//int dispCount = 1;

	for(i = 1; i < n; i ++)
		minCost += arr[permArr[i].val][permArr[i + 1].val];		

	minCost += arr[permArr[i].val][permArr[1].val];

	while(m != -1)
	{
		//printf("%d", dispCount ++);
		
		int index;
		struct Element temp;	//for swapping
		
		if(permArr[m].dir == 'l')
			index = m - 1;
		else
			index = m + 1;
		
		temp = permArr[m];
		permArr[m] = permArr[index];
		permArr[index] = temp;
		
		changeDir(permArr, n, index);
		
		minCost = calcCost(n, arr, permArr, minCost); //to calculate the minimum cost
		
		m = greatestMobElem(permArr, n);
	}
	
	printf("The minimum cost is : %d\n", minCost);

	return 0;
}

int calcCost(int n, int** arr, struct Element permArr[], int minCost)
{
	int tempCost = 0;
	int i,j;
	/*
	for(j=1;j<=n;j++)
	{
		printf("%2d",permArr[j].val);
	}
	printf(" ");
	*/
	for(i = 1; i < n; i ++)
	{
	//	printf("%d + ",arr[permArr[i].val][permArr[i + 1].val]);
		tempCost += arr[permArr[i].val][permArr[i +1].val];	
	}
	//printf("%d = ", arr[permArr[i].val][permArr[1].val]);
	tempCost += arr[permArr[i].val][permArr[1].val];
	//printf("tempcost %d\n",tempCost);
	if(tempCost < minCost)
		minCost = tempCost;
	
	return minCost;
}

void changeDir(struct Element permArr[], int n, int i)
{
	int j;
	for(j = 1; j <= n; j ++)
	{
		if(permArr[j].val > permArr[i].val)
		{
			if(permArr[j].dir == 'l')
				permArr[j].dir = 'r';
			else
				permArr[j].dir = 'l';
		}
	}
}

int greatestMobElem(struct Element permArr[], int n)
{
	int m = -1;
	int i;
	for(i = 1; i <= n; i++)
	{
		if(permArr[i].dir == 'l' && (i > 1) && (permArr[i].val > permArr[i - 1].val))
		{
			if(m == -1)
				m = i;
			else if(permArr[i].val > permArr[m].val)
				m = i;
		}
		
		else if(permArr[i].dir == 'r' && (i < n) && (permArr[i].val > permArr[i + 1].val))
		{
			if(m == -1)
				m = i;
			else if(permArr[i].val > permArr[m].val)
				m = i;
		}
	}
	return m;
}