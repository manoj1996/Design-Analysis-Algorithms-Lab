#include<stdio.h>
#include<stdlib.h>
struct fringe
{
	int vertex;
	int distTo;
};
int Prim(int** f,int n);
int check(int* marked,int n);
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int** a = malloc(sizeof(int*)*n);
	for(i = 0;i < n;i++)
		a[i] = malloc(sizeof(int)*n);
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			scanf("%d",&a[i][j]);
	int l = Prim(a,n);
	printf("Min:%d\n",l);
	return 0;
} 
int Prim(int** f,int n)
{
	int i,j;
	int maxf = (n*(n-1))/2;
	int cf = 0;//count of number of vertices in the mst
	int sum = 0;
	int minv = 0;
	int p = 0;//points to the current vertex
	struct fringe* fedge = malloc(sizeof(struct fringe)*maxf);
	int* marked = calloc(n,sizeof(int));
	while(check(marked,n) == 0)
	{
		marked[p] = 1;
		for(i = 0;i < n;i++)
		{
			if(f[p][i] != 0 && f[p][i] != 1000 )
			{
				struct fringe temp;
				temp.vertex = i;
				temp.distTo = f[p][i];
				fedge[cf++] = temp;
			}
		}
		int mind = 0;
		for(j = 0;j < cf;j++)
		{
			if(marked[fedge[j].vertex] == 0)
			{
				if(fedge[j].distTo < mind || mind == 0)
				{
					minv = fedge[j].vertex;
					mind = fedge[j].distTo;
				}
			}
		}
		sum += mind;
		p = minv;
		marked[p] = 1;
	}
	return sum;
}
int check(int* marked,int n)
{
	int i;
	for(i = 0;i < n;i++)
	{
		if(marked[i] == 0)
			return 0;
	}
	return 1;
}

