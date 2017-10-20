#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node* next;
};

int* topoSort(int** a, int order);
struct node* dfs(struct node* front, int** a, int* mark, int order, int j);

int main()
{
	int order;
	int i, j;
	int** arr;
	int* res;
	
	scanf("%d", &order);
	res = malloc(sizeof(int) * order);
	
	
	arr = malloc(sizeof(int*) * (order + 1));
	for(i = 1; i <= order; i++)
		arr[i] = malloc(sizeof(int) * (order + 1));
	
	for(i = 1; i <= order; i++)
		for(j = 1; j <= order; j++)
			scanf("%d", &arr[i][j]);
	
	res = topoSort(arr, order);
	
	for(i = 1; i <= order; i++)
		printf("%d\n", res[i]);
	
	return 0;
}

int* topoSort(int** a, int order)
{
	int i, j, c;
	int count = 0;
	
	int* intArr = malloc(sizeof(int) * (order + 1));

	struct node* front = NULL;

	int* mark = malloc(sizeof(int) * (order + 1));
	for(i = 1; i <= order; i++)
		mark[i] = 0;
	
	for(j = 1; j <= order; j++)
	{
		if(mark[j] == 0)
		{
			front = dfs(front, a, mark, order, j);
			count ++;
		}
	}
	c = 1;
	while(front != NULL)
	{
		intArr[c++] = front -> value;
		front = front -> next;
	}
	
	return intArr;
}

struct node* dfs(struct node* front, int** a, int* mark, int order, int j)
{
	int i;
	
	if(mark[j] == 1)
		printf("The graph is not a DAG!\n");
	else if(mark[j] == 0)
	{
		mark[j] = 1;
	
		for(i = 1; i <= order; i++)
			if(a[j][i] == 1)
				front =	dfs(front, a, mark, order, i);
		
		mark[j] = 2;
		struct node* temp = malloc(sizeof(struct node) * 1);
		temp -> value = j - 1;
		temp -> next = front;
		front = temp;
	}
	return front;
}

/*
Algorithm DFS_Toposort(V, E)
L ← Empty list that will contain the sorted vertices
for each vertex v in V { popped(v) = 0, mark(v) = 0 }
for each vertex v do
	if(popped(v) = 0) visit(v)

Procedure visit(vertex v)
if pushed(v) != 0 then return error (not a DAG)
if popped(v) = 0 then
	pushed(v) = 1
	for each vertex m with an edge from v to m do
		visit(m)
	popped(v) = 1, pushed(v) = 0
	add v at head of L
*/
