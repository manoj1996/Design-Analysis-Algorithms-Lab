#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void sort();
double execTime(struct timespec start, struct timespec end);

int main(void)
{
	int n;	//number of elements in the array
	
	scanf("%d", &n);
	
	sort(n);

	return 0;
}

void sort(int n)
{
	int * arr = malloc(sizeof(int) * (n + 1));	//array of integers; requires <stdlib.h>
	int i;
	int j;
	int temp;
	struct timespec start, end;
	
	for(i = 0; i < n; i ++)
		scanf("%d", &arr[i]);
	
	/*
	printf("Original array :\n");

	for(i = 0; i < n; i ++)
		printf("%d\n", arr[i]);
	
	printf("\n");
	*/
	
	clock_gettime(CLOCK_REALTIME, &start);
	//Bubble Sort
	for(i = 0; i < n - 1; i ++)
		for(j = 0; j < n - 1 - i; j ++)
			if(arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	//end of Bubble Sort
	clock_gettime(CLOCK_REALTIME, &end);
	
	//printf("Sorted array :\n");
	for(i = 0; i < n; i ++)
		printf("%d\n", arr[i]);

	printf("\nExecution time for Bubble Sort : %lf ms\n", execTime(start, end));
}

double execTime(struct timespec start, struct timespec end)
{
	double t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	return t;
}
