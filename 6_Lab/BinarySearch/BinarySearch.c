#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Student
{
	char srn[9];
	char name[15];
	float gpa;
};

int binarySearchRec(struct Student s[], int l, int r, char* key);
double execTime(struct timespec start, struct timespec end);

int main()
{
	int n;
	int i = 0;
	int l;
	int r;
	int result;
	char key[15];

	scanf("%d", &n);	
	struct Student* s = malloc(sizeof(struct Student) * (n));
	struct timespec start, end;
	
//	printf("%d\n", n);//db
	for(i = 0; i < n; i ++)
	{
		scanf("%s", s[i].srn);
		scanf("%s", s[i].name);
		scanf("%f", &s[i].gpa);
	}
	scanf("%s", key);
	
	/*check
	for(i = 0; i < n; i ++)
	{
		printf("%s\t", s[i].srn);
		printf("%s\t", s[i].name);
		printf("%.2f\n", s[i].gpa);
	}
	printf("%s\n", key);
	*/
	
	l = 0;
	r = n - 1;
	
	clock_gettime(CLOCK_REALTIME, &start);
	
	result = binarySearchRec(s, l, r, key);
	
	clock_gettime(CLOCK_REALTIME, &end);

	printf("%d\n", result);
	printf("Execution Time : %lf microseconds\n", execTime(start, end));
	return 0;
}

int binarySearchRec(struct Student s[], int l, int r, char* key)
{	
	if(l > r)
		return -1;

	int mid;
		
	mid = (l + r) / 2;
	
	if(strcmp(key, s[mid].name) < 0)
		return binarySearchRec(s, l, mid - 1, key);

	else if(strcmp(key, s[mid].name) > 0)
		return binarySearchRec(s, mid + 1, r, key);
	
	else
	{
		while(mid > 0 && strcmp(s[mid - 1].name, s[mid].name) == 0)
		{
			mid --;
		}
		return mid;
	}
}

double execTime(struct timespec start, struct timespec end)
{
	double t = (end.tv_sec - start.tv_sec) * 1000000;
	t += (end.tv_nsec - start.tv_nsec) * 0.001;
	return t;
}
