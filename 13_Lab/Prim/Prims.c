#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//double time_elapsed(struct timespec start, struct timespec end);
struct node
{
	int vert;
	int key;
};
int Prim(struct node*vertex,int size,int **edge);
void TocreateHeap(struct node *student,int size);
void Heapify(struct node *student,int k,int size);
struct node Maxkeydelete(struct node*student,int k);
int main()
{
	//struct timespec start,end;
	int size,i,j;
	scanf("%d",&size);
	struct node *vertex=malloc(sizeof(struct node)*(size+1));
	int **edge=malloc(sizeof(int*)*(size+1));
	for(i=0;i<=size;i++)
		edge[i]=malloc(sizeof(int)*(size+1));
	for(i=1;i<=size;i++)
		for(j=1;j<=size;j++)
			scanf("%d",&edge[i][j]);
	for(i=1;i<=size;i++)
	{
		vertex[i].vert=i;
		if(i==1)
			vertex[i].key=0;
		else
			vertex[i].key=1000;
	}
	/*for(i=1;i<=size;i++)
	{
		printf("%d\t",vertex[i].vert);
		printf("%d\t",vertex[i].key);
		printf("\n");
	}
	printf("The ede matrix \n");
	for(i=0;i<=size;i++)
	{
		for(j=0;j<=size;j++)
			printf("%d\t",edge[i][j]);
		printf("\n");
	}*/
	TocreateHeap(vertex,size);
	printf(" Shotest Path : %d\n", Prim(vertex,size,edge));
	


	//printf("Execution time: %.6lf millisec.\n", time_elapsed(start, end));
	free(vertex);
	return 0;
}
void TocreateHeap(struct node*vertex,int size)
{
	int i;
	for(i=size/2;i>=1;i--)
		Heapify(vertex,i,size);

	/*for(i=size;i>=2;i--)
		Maxkeydelete(vertex,i);*/
}
void Heapify(struct node *vertex,int k,int size)
{
	int j;
	if(2*k>size)
		 return;
	if(2*k<=size)
	{
		j=2*k;
		if(j<size && (vertex[2*k+1].key < vertex[2*k].key))
			j=2*k+1;
		if(vertex[k].key>vertex[j].key)
		{	
			struct node temp=vertex[k];
			vertex[k]=vertex[j];
			vertex[j]=temp;
		}
		Heapify(vertex,j,size);
	}
}
struct node Maxkeydelete(struct node*vertex,int k)
{
	struct node temp=vertex[1];
	vertex[1]=vertex[k];
	vertex[k]=temp;
	Heapify(vertex,1,k-1);
	return temp;
}
	
int Prim(struct node*vertex,int size,int **edge)
{
	int i,j,k,sum=0;
	struct node temp;
	for(i=size;i>=2;i--)
	{	
		temp=Maxkeydelete(vertex,i);
		sum+=temp.key;
		for(j=1;j<=size;j++)
		{
	
			if(temp.vert!=j && edge[temp.vert][j]<1000)
			{
				for(k=1;k<i;k++)
					if(vertex[k].vert==j)
						if(vertex[k].key > edge[temp.vert][j])
							vertex[k].key=edge[temp.vert][j];
			}
		}
		TocreateHeap(vertex,i-1);				
	}
	sum+=vertex[1].key;				
	return sum;
}			
		













