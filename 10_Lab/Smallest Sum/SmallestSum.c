#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void input(int n);
void smallestSum(int s[], int n);
void mergeSort(int s[], int n);
void merge(int s1[], int p, int s2[], int q, int s[]);
void display(int s[], int n);
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
	int i, final;
	//struct timespec start;
	//struct timespec end;
	
	int* s = malloc(sizeof(int) * (n + 1));
	
	//s = malloc(sizeof(struct Student) * (n + 1));	//use a buffer array here for temporary copy to increase efficiency
	
	for(i = 0; i < n + 1; i ++)
		scanf("%d", &s[i]);
	final = s[n];
	//clock_gettime(CLOCK_REALTIME, &start);
	mergeSort(s, n);
	//clock_gettime(CLOCK_REALTIME, &end);
	
	//display(s, n);
	
	smallestSum(s, final);
	
	//printf("\n Execution Time : %lf ms \n", execTime(start, end));
}

void smallestSum(int s[], int final)
{
	int i, sum;
	
	sum = 0;
	
	for(i = 0; i < final; i++)
		sum += s[i];
	
	printf("%d\n", sum);
	//printf("The sum of the smallest %d numbers is : %d\n", 3, sum);
}

void mergeSort(int s[], int n)
{
	if(n > 1)
	{
		int i;
		int p = (int)floor(n / 2.0);	// divide by 2.0 IMP
		int q = (int)ceil(n / 2.0);	//type "gcc -Wall Test.c -lm" to compile the program successfully

		int* s1;
		int* s2;
		s1 = malloc(sizeof(int) * (p));
		s2 = malloc(sizeof(int) * (q));
		
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

void merge(int s1[], int p, int s2[], int q, int s[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	int x;
	
	while(i < p && j < q)
	{
		if(s1[i] <= s2[j])
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

void display(int s[], int n)
{
	int i;
	//printf("n : %d \n", n);//db
	printf("\n");
	
	for(i = 0; i < n; i ++)
		printf("%d\n", s[i]);
	
	printf("\n");
}

double execTime(struct timespec start, struct timespec end)
{
	double t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	
	return t;
}
