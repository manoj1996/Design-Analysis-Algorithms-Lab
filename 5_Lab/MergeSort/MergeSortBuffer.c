#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

struct Student
{
	char srn[6];	//"char* srn;" yields segmentation fault since size is not defined
				//includes the '\0', hence srn[6] for a 5 char srn; srn[5] appends srn and name to srn. Why?
	char name[15];
	float gpa;	//should be upto 2 decimal places
};

void input(int n);
void mergeSort(struct Student s[], int n);
void merge(struct Student s1[], int p, struct Student s2[], int q, struct Student s[]);
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
	struct timespec start;
	struct timespec end;
		
	struct Student* s;
	s = malloc(sizeof(struct Student) * (n + 1));	//use a buffer array here for temporary copy to increase efficiency
	
	for(i = 0; i < n; i ++)
	{
		scanf("%s", s[i].srn);
		scanf("%s", s[i].name);
		scanf("%f", &s[i].gpa);
		//printf("%s %s %.2f\n", s[i].srn, s[i].name, s[i].gpa);//db
	}
	//display(s, n);//db

	clock_gettime(CLOCK_REALTIME, &start);
	mergeSort(s, n);
	clock_gettime(CLOCK_REALTIME, &end);
	
	display(s, n);
	
	printf("\n Execution Time : %lf ms \n", execTime(start, end));
}

void mergeSort(struct Student s[], int n)
{
	if(n > 1)
	{
		int i;
		int p = (int)floor(n / 2.0);	// divide by 2.0 IMP
		int q = (int)ceil(n / 2.0);	//type "gcc -Wall Test.c -lm" to compile the program successfully

		struct Student* s1;
		struct Student* s2;
		s1 = malloc(sizeof(struct Student) * (p));
		s2 = malloc(sizeof(struct Student) * (q));
		
		for(i = 0; i < p; i ++)	//copy first half into s1
			s1[i] = s[i];
		//check
		//display(s1, p);
		//
		int c = 0;
		for(i = p; i < n && c < q; i ++)	//copy second half into s2
			s2[c ++] = s[i];
		//check
		//display(s2, q);
		//
		
		mergeSort(s1, p);
		mergeSort(s2, q);
		merge(s1, p, s2, q, s);
	}
}

void merge(struct Student s1[], int p, struct Student s2[], int q, struct Student s[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	int x;
	
	while(i < p && j < q)
	{
		if(strcmp(s1[i].name, s2[j].name) <= 0)
			s[k ++] = s1[i ++];
		else
			s[k ++] = s2[j ++];
	}
	
	if(i == p)
		for(x = j; x < q; x ++)
			s[k ++] = s2[x];
	else
		for(x = i; x < p; x ++)
			s[k ++] = s1[x];
			
	//display(s, p + q - 1);//db
}

void display(struct Student s[], int n)
{
	int i;
	//printf("n : %d \n", n);//db
	printf("\n");
	
	for(i = 0; i < n; i ++)
		printf("%s %s %.2f\n", s[i].srn, s[i].name, s[i].gpa);
	
	printf("\n");
}

double execTime(struct timespec start, struct timespec end)
{
	double t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	
	return t;
}
