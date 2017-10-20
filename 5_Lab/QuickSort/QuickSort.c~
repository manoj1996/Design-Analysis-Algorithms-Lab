#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Student
{
	char srn[9]; //can we use "malloc(sizeof(char) * 5)" here?
	char name[15];
	float gpa;	//should be upto 2 decimal places
};

void input(int n);
void quickSort(struct Student s[], int l, int r);
int hoarePartition(struct Student s[], int l, int r);
void swap(struct Student s[], int i, int j);
void display(struct Student s[], int n);
double execTime(struct timespec start, struct timespec end);

int main()
{
	int n;
	
	scanf("%d", &n);
	
	input(n);
	
	return 0;
}

void input(int n)
{
	int i;
	int l = 0;
	int r = n - 1;
	struct timespec start;
	struct timespec end;
	
	struct Student* s;
	s = malloc(sizeof(struct Student) * n);
	
	for(i = 0; i < n; i ++)
	{
		scanf("%s", s[i].srn);
		scanf("%s", s[i].name);
		scanf("%f", &s[i].gpa);
	}
	
	/* check
	printf("\n");
	for(i = 0; i < n; i ++)
	{
		printf("%s\t", s[i].srn);
		printf("%s\t", s[i].name);
		printf("%f\n", s[i].gpa);
	}
	printf("\n");
	*/
	clock_gettime(CLOCK_REALTIME, &start);
	quickSort(s, l, r);
	clock_gettime(CLOCK_REALTIME, &end);
	
	printf("\nExecution Time : %lf ms \n", execTime(start, end));
	display(s, n);
}

void quickSort(struct Student s[], int l, int r)
{
	int splitPos;
	
	if(l < r)
	{
		splitPos = hoarePartition(s, l, r);
		quickSort(s, l, splitPos - 1);
		quickSort(s, splitPos + 1, r);
	}
}

int hoarePartition(struct Student s[], int l, int r)
{
	char* pivot = malloc(sizeof(char) * 5);
	strcpy(pivot, s[l].srn);
	
	int i = l;
	int j = r;	//not r + 1
	
	while(i < j)	//not i <= j
	{
		while(strcmp(s[i].srn, pivot) <= 0 && i < r)	//i < r IMP
		{
			i ++;
		}
		
		while(strcmp(s[j].srn, pivot) > 0)
		{
			j --;
		}
		
		if(i < j)	//if already swapped, don't swap
			swap(s, i, j);
	}
	
	swap(s, l, j);
	
	return j;
}

void swap(struct Student s[], int i, int j)
{
	struct Student temp;

	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

void display(struct Student s[], int n)
{
	int i;
	
	for(i = 0; i < n; i ++)
		printf("%s %s %.2f \n", s[i].srn, s[i].name, s[i].gpa);
}

double execTime(struct timespec start, struct timespec end)
{
	double t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	
	return t;
}
