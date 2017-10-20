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
void distributionSort(struct student* records, int n);
void display(struct student** final, int* count, int n);

int main()
{
	int i, n;
	
	scanf("%d", &n);
	
	struct student* records = malloc(sizeof(struct student) * (n + 1));
	
	for(i = 0; i < n; i++)
	{
		scanf("%s", records[i].srn);
		scanf("%s", records[i].name);
		scanf("%d", &records[i].marks);
	}
	
	distributionSort(records, n);
	
	return 0;
}

void distributionSort(struct student* records, int n)
{
	int i;

	int* count = (int*)calloc(101, sizeof(int));		//sets the default value of int => 0
	
	struct student** final = malloc(sizeof(struct student*) * 101);
	for(i = 0; i < 101; i++)
		final[i] = malloc(sizeof(struct student) * n);	//worst case => everyone has the same percentages
	
	for(i = 0; i < n; i++)
	{
		final[records[i].marks][count[records[i].marks]] = records[i];
		count[records[i].marks]++;
	}
	
	display(final, count, n);
}

void display(struct student** final, int* count, int n)
{
	int i, j;
	
	for(j = 100; j >= 0; j--)
		for(i = 0; i < count[j]; i++)
			printf("%s %s %d\n", final[j][i].srn, final[j][i].name, final[j][i].marks);
}
