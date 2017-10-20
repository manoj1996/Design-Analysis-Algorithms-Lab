#include<stdio.h>
#include<time.h>

int seqSearch();
double execTime(struct timespec start, struct timespec end);

int main(void)
{
	int tc; //total cases
	struct timespec start, end;

	scanf("%d", &tc);

	clock_gettime(CLOCK_REALTIME, &start);

	while(tc--)
	{
		printf("%d\n", seqSearch());
	}
	
	clock_gettime(CLOCK_REALTIME, &end);
	printf("Execution time : %lf ms\n", execTime(start, end));
	
	return 0;
}

int seqSearch()	//should have all declarations before execution statements! (using scanf between declaration and definition of arrSiz not advisable.)
{
	int arrSiz;		//array size
	scanf("%d", &arrSiz);
	int arr[arrSiz];
	
	//debug - to check if junk value is the same when this file is executed any number of times
	//printf("Size : %ld\n", sizeof(arr));
	
	int i;
	for(i = 0; i < arrSiz; i ++)
		scanf("%d", &arr[i]);
	
	int k;	//search value
	scanf("%d", &k);
	
	for(i = 0; i < arrSiz; i ++)
		if(arr[i] == k)
			return i;
	return -1;
}

double execTime(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	return t;
}
