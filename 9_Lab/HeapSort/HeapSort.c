#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct student
{
	char srn[9];
	char name[15];
	int marks;	
};

void input(int n);
void heapSort(struct student* records, int n);
void maxKeyDelete(struct student* records, int n);
void heapBottomUp(struct student* records, int n);
void heapify(struct student* records, int k, int n);
void display(struct student* records, int n);

int main()
{
	int i, n;
	
	scanf("%d", &n);
	
	struct student* records = malloc(sizeof(struct student) * (n + 1));
	
	for(i = 1; i <= n; i++)
	{
		scanf("%s", records[i].srn);
		scanf("%s", records[i].name);
		scanf("%d", &records[i].marks);
	}
	
	heapSort(records, n);
	
	display(records, n);
	
	return 0;
}

void heapSort(struct student* records, int n)
{
	int i;
	
	heapBottomUp(records, n);
	
	for(i = n; i > 1; i--)
		maxKeyDelete(records, i);
}

void heapBottomUp(struct student* records, int n)
{
	int i;

	if(n <= 1)
		return;
	
	for(i = floor(n / 2); i > 0; i--)
		heapify(records, i, n);
}

void heapify(struct student* records, int k, int n)
{
	int j;

	if(2 * k > n)
		return;
	
	struct student temp;
	j = 2 * k;
	if(j + 1 <= n)	
		if(strcmp(records[j + 1].srn, records[j].srn) > 0)
			j += 1;
	
	if(strcmp(records[j].srn, records[k].srn) > 0)
	{
		temp = records[j];
		records[j] = records[k];
		records[k] = temp;
		
		heapify(records, j, n);
	}
}

void maxKeyDelete(struct student* records, int n)
{
	struct student temp;
	
	temp = records[1];
	records[1] = records[n];
	records[n] = temp;
	
	heapify(records, 1, n - 1);
}

void display(struct student* records, int n)
{
	int i;
	
	for(i = 1; i <= n; i++)
		printf("%s %s %d\n", records[i].srn, records[i].name, records[i].marks);
}
