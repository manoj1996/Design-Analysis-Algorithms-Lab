#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

void prependZeroes(char a[], char b[]);
char* karatsubaMultiply(char* a, char* b, int k);
char** split_at(char* c, int mid);
char* intToString(int product);
char* add(char* a, char* b);
char* sub(char a[], char b[]);
char* powerOfTen(char c[], int x);
void trim(char c[]);

int main()
{
	int k;
	char* a = malloc(sizeof(char) * 1000000);
	char* b = malloc(sizeof(char) * 1000000);

	scanf("%s", a);
	scanf("%s", b);
	
	//To modify a[] and b[] such that the count of their digits is a power of 2 and strlen(a) = strlen(b)
	prependZeroes(a, b);

	k = log2(strlen(a));
	
	printf("Multiplication yields : %s\n", karatsubaMultiply(a, b, k));
	
	return 0;
}

void prependZeroes(char a[], char b[])
{
	int l1, l2;
	int l;
	int i, j, k;
	
	l1 = strlen(a);	//strlen in printf requires format specifier %zu
	l2 = strlen(b);
	
	l1 > l2 ? (l = l1) : (l = l2);

	i = 1;
	while(i < l)
	{
		i *= 2;	
	}
	
	l = i;

	char* tempA = malloc(sizeof(char) * l);
	char* tempB = malloc(sizeof(char) * l);
	
	for(i = 0; i < l - l1; i++)
		tempA[i] = '0';
	
	k = 0;
	for(j = i; j < l; j ++)
		tempA[j] = a[k ++];
	
	
	for(i = 0; i < l - l2; i ++)
		tempB[i] = '0';
	
	k = 0;
	for(j = i; j < l; j ++)
		tempB[j] = b[k ++];
	
	strcpy(a, tempA);
	strcpy(b, tempB);
}

char* karatsubaMultiply(char a[], char b[], int k)
{
	if(k == 0)
	{
		char* result;
		int product;
		
		product = (a[0] - '0') * (b[0] - '0');
		result = intToString(product);
		return result;
	}
	
	int m, m2, l1, l2, z, l = 0;
	char* a1;
	char* a2;
	char* a3;
	char* b1;
	char* b2;
	char* b3;
	char* p1;
	char* p2;
	char* p3;
	char** x;
	char* res1;
	char* res2;
	char* res3;
	char* final;
	char* temp;
	
	m = pow(2, k);
	m2 = m / 2;
	
	x = split_at(a, m2);
	a1 = x[0];
	a2 = x[1];
	
	x = split_at(b, m2);
	b1 = x[0];
	b2 = x[1];
	
	prependZeroes(a1, a2);
	prependZeroes(b1, b2);
	a3 = add(a1, a2);
	b3 = add(b1, b2);
	trim(a3);
	trim(b3);
	
	l1 = strlen(a3);	
	l2 = strlen(b3);

	l1 > l2 ? (l = l1) : (l = l2);

	z = ceil(log2(l));
	prependZeroes(a3, b3);
	
	p1 = karatsubaMultiply(a1, b1, k - 1);
	p2 = karatsubaMultiply(a2, b2, k - 1);
	p3 = karatsubaMultiply(a3, b3, z);
	
	//res1
	res1 = powerOfTen(p1, m);
	
	//res2
	prependZeroes(p3, p1);
	temp = sub(p3, p1);
	prependZeroes(temp, p2);
	temp = sub(temp, p2);
	trim(temp);
	res2 = powerOfTen(temp, m2);
	
	//res3
	res3 = p2;
	
	//final
	trim(res1);
	trim(res2);
	trim(res3);	
	prependZeroes(res1, res2);
	temp = add(res1, res2);
	trim(temp);
	prependZeroes(temp, res3);
	final = add(temp, res3);
	trim(final);
	return final;
	//return (p1 * powerOfTen(10, m) + (p3 - p1 - p2) * powerOfTen(10, m2) + p2);
}

void trim(char c[])
{
	int l = strlen(c);

	int i, j, k;
	
	j = -1;	//if c = '00', it should be transformed into '0'
	for(i = 0; i < l; i++)
		if(c[i] != '0')
		{
			j = i;
			break;
		}

	if(j == -1)
	{
		char* temp = malloc(sizeof(char) * 1);
		temp[0] = '0';
		strcpy(c, temp);
	}
	else
	{
		char* temp = malloc(sizeof(char) * (l - j + 1));	//VIMP l - j + 1 ; not l - j

		k = 0;
		for(i = j; i < l; i++)
			temp[k++] = c[i];
		strcpy(c, temp);
	}
}

char* add(char a[], char b[])
{
	int i, j, x;
	int l;
	l = strlen(a);
	char* c = malloc(sizeof(char) * (l + 2));
	int carry = 0;
	
	for(i = l; i >= 0 ; i --)
	{
		if(i == 0)
			c[i] = carry + '0';
		else
		{
			x = 0;
			j = i - 1;	//since strlen(c) is greater than strlen(a) by 1; strlen(a) is the same as that of strlen(b)
			x = (a[j] - '0') + (b[j] - '0') + carry;
		
			if(x > 9)
			{
				carry = x / 10;
				x = x % 10;
			}
			else
				carry = 0;
		
			c[i] = x + '0';
		}
	}

	c[l + 1] = '\0';
	
	trim(c);	//VVIMP to keep the size of the array a minimum
	char* hack = malloc(sizeof(char) * strlen(c));
	if(strlen(c) == 2 && c[0] == 0)
	{
		hack[0] = c[1];
		strcpy(c, hack);
	}
	else
	{
		for(i = 0; i < strlen(c); i++)
			hack[i] = i + '0';
		prependZeroes(c, hack);
	}
	return c;
}

char* sub(char a[], char b[])
{
	int i, j, x;
	int l;
	char* temp = malloc(sizeof(char) * strlen(a));
	l = strlen(a);
	char* c = malloc(sizeof(char) * (l));
	int borrow;
	
	//moving a into temp since the array a[] (now temp) has to be modified while considering a borrow
	strcpy(temp, a);
		
	for(i = l - 1; i >= 0 ; i --)
	{
		x = 0;
		if(temp[i] < b[i])
		{
			borrow = 1;
			j = temp[i - 1] - '0';
			j -= 1;
			j += '0';
			temp[i - 1] = j;
			x = pow(10, borrow) + (temp[i] - '0') - (b[i] - '0');
		}
		else
			x = (temp[i] - '0') - (b[i] - '0');
	
		c[i] = x + '0';
	}
	
	char* hack = malloc(sizeof(char) * strlen(c));
	for(i = 0; i < strlen(c); i++)
		hack[i] = i + '0';
	prependZeroes(c, hack);
	return c;
}

char* powerOfTen(char p[], int m)
{
	int i, j;
	char* res = malloc(sizeof(char) * (strlen(p) + m));
	
	for(i = 0; i < strlen(p); i++)
		res[i] = p[i];
	for(j = 0; j < m; j++)
		res[i++] = '0';
	
	return res;
}

char** split_at(char* c, int mid)
{
	int i = 0, j, k;
	int l = strlen(c);
	char** s = malloc(sizeof(char*) * 2);
	
	for(i = 0; i < 2; i ++)
		s[i] = malloc(sizeof(char) * mid);
	
	for(j = 0; j < mid; j ++)
		s[0][j] = c[j];

	k = 0;
	for(j = mid; j < l; j ++)
		s[1][k++] = c[j];
	
	return s;
}

char* intToString(int product)
{
	int temp = product;
	int c = 0;
	
	if(temp == 0)
	{
		char* morphed = malloc(sizeof(char) * 1);
		morphed[0] = '0';
		return morphed;
	}
	
	while(temp)
	{
		temp /= 10;
		c++;
	}
	char* morphed = malloc(sizeof(char) * c);

	temp = product;
	c -= 1;
	while(temp)
	{
		morphed[c--] = (temp % 10) + '0';	//Adding '0' very important!
		temp /= 10;
	}
	
	return morphed;
}