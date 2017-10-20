#include<stdio.h>
#include<stdlib.h>
struct fringe
{
	int vertex;
	int distTo;
};
int* Dijkstra(int** f,int n,int s,int d);
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
	int s,d;
	scanf("%d",&s);
	scanf("%d",&d);
	int* l = Dijkstra(a,n,s,d);
	printf("Distance:%d\n",l[0]);
	int k = 1;
	while(l[k] != d && k < n+1)
	{
		printf("%d   ",l[k]);
		k++;
	}
	printf("%d   \n",l[k]);
	return 0;
} 
int* Dijkstra(int** f,int n,int s,int d)
{
	int i,j;
	int cf = 0;//count of number of vertices in the mst
	int sum = 0;
	int minv = 0;
	int z = 1;
	int p = s;//points to the current vertex
	int* res = calloc(n+1,sizeof(int));
	struct fringe* fedge = malloc(sizeof(struct fringe)*n);
	while(p != d)
	{
		res[z++] = p;
		for(i = 0;i < n;i++)
		{
			if(f[p][i] != 0)
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
			if(fedge[j].distTo < mind || mind == 0)
			{
				minv = fedge[j].vertex;
				mind = fedge[j].distTo;
			}
		}
		sum += mind;
		p = minv;
		cf = 0;
	}
	res[z++] = p;
	res[0] = sum;
	return res;
}

