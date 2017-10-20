#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n);
void display(int arr[], int n);
double execTime(struct timespec start, struct timespec end);

int main()
{
	int n;
	int i;
	struct timespec start, end;
	
	scanf("%d\n", &n);
	
	printf("\n");
	
	int* arr = malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	clock_gettime(CLOCK_REALTIME, &start);
	insertionSort(arr, n);
	clock_gettime(CLOCK_REALTIME, &end);
		
	display(arr, n);
	
	printf("Execution Time : %lf ms\n", execTime(start, end));
	printf("\n");
	
	return 0;
}

void insertionSort(int arr[], int n)
{
	int i;
	int j;
	int k;
	
	for(i = 1; i < n; i++)
	{
		k = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = k;
	}
}

void display(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}

double execTime(struct timespec start, struct timespec end)
{
	double t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	
	return t;
}
