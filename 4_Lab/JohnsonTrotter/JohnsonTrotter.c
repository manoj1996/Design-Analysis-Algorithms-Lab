#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Element
{
	int val;
	char dir;
};

void genPerm(int arr[], int n);
int greatestMobElem(struct Element permArr[], int n);
void changeDir(struct Element permArr[], int p, int i);

int main()
{
	int n;	//where there are n! permutations possible
	int i;
	
	scanf("%d", &n);
	int arr[n];
	
	
	for(i = 0; i < n; i ++)
	{
		scanf("%d", &arr[i]);
	}
	
	genPerm(arr, n);
	
	return 0;
}

void genPerm(int arr[], int n)
{
	int i;
	
	for(i = 0; i < n; i ++)
	{
		int p = arr[i];
		struct Element permArr[p];	//contains the numbers from 1 upto the input number
		int j;
		
		for(j = 1; j <= p; j ++)
		{
			permArr[j].val = j;
			permArr[j].dir = 'l';
		}
		
		int m = greatestMobElem(permArr, p);

		int dispCount = 1;
		while(m != -1)
		{
			printf("%d", dispCount ++);
			
			//add p to the list
			int x;
			for(x = 1; x <= p; x ++)
			{
				if(permArr[x].dir == 'l')
					//printf("%d ", permArr[x].val);
					printf(" <= %d", permArr[x].val);
				else
					//printf("%d ", permArr[x].val);
					printf(" => %d", permArr[x].val);
			}
			printf("\n");
			//
			
			int index;
			struct Element temp;	//for swapping
			
			if(permArr[m].dir == 'l')
				index = m - 1;
			else
				index = m + 1;
			
			temp = permArr[m];
			permArr[m] = permArr[index];
			permArr[index] = temp;
			
			changeDir(permArr, p, index);
			
			m = greatestMobElem(permArr, p);
			//printf("m : %d\n", m);	debug
		}
		
		//add last p to the list
		printf("%d", dispCount);
		int x;
		for(x = 1; x <= p; x ++)
		{
			if(permArr[x].dir == 'l')
				//printf("%d ", permArr[x].val);
				printf(" <= %d", permArr[x].val);
			else
				//printf("%d ", permArr[x].val);
				printf(" => %d", permArr[x].val);
		}
		printf("\n");
		//
	}
}

void changeDir(struct Element permArr[], int n, int i)
{
	int j;
	for(j = 1; j <= n; j ++)
	{
		if(permArr[j].val > permArr[i].val)
		{
			if(permArr[j].dir == 'l')
				permArr[j].dir = 'r';
			else
				permArr[j].dir = 'l';
		}
	}
}

int greatestMobElem(struct Element permArr[], int n)
{
	int m = -1;
	int i;
	for(i = 1; i <= n; i++)
	{
		if(permArr[i].dir == 'l' && (i > 1) && (permArr[i].val > permArr[i - 1].val))
		{
			if(m == -1)
				m = i;
			else if(permArr[i].val > permArr[m].val)
				m = i;
		}
		
		else if(permArr[i].dir == 'r' && (i < n) && (permArr[i].val > permArr[i + 1].val))
		{
			if(m == -1)
				m = i;
			else if(permArr[i].val > permArr[m].val)
				m = i;
		}
	}
	return m;
}
