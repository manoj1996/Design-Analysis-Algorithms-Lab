#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int horspoolMatching(char p[], char t[]);
int* shiftTable(char p[]);

int main()
{
	char* text = malloc(sizeof(char) * 1000000);
	char* pattern = malloc(sizeof(char) * 1000000);
	
	scanf("%s", text);
	scanf("%s", pattern);
	
	printf("Index of the first letter of the first matching substring : %d\n", horspoolMatching(pattern, text));
	
	return 0;
}

int horspoolMatching(char p[], char t[])
{
	int m, n, i, k;	
	
	int* table = shiftTable(p);
	m = strlen(p);
	n = strlen(t);
	
	i = m - 1;
	while(i <= n - 1)
	{
		k = 0;
		while(k <= m - 1 && p[m - 1 - k] == t[i - k])
		{
			k++;
		}
		
		if(k == m)
			return i - m + 1;
		else
			i = i + table[(int)t[i]];
	}
	return -1;
}

int* shiftTable(char p[])
{
	int i, j, size, m;
	int* table = malloc(sizeof(char) * 123);
	
	m = strlen(p);
	
	size = 124;	//123 => size - 1 doesn't enter the loop
	
	for(i = 0; i < size - 1; i++)
		table[i] = m;
	for(j = 0; j < m - 1; j++)
		table[(int)p[j]] = m - 1 - j;

	return table;
}
