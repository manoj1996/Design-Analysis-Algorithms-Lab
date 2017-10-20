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
	
	//printf("Multiplicand : %s\n", a);//db
	//printf("Multiplier : %s\n", b);//db
	
	k = log2(strlen(a));
	//printf("k : %d\n", k);//db
	
	//printf("a + b : %s\n", add(a, b));//db
	/*
	//debug
	char x[5] = {'8', '3', '7', '6'};
	char y[5] = {'7', '9', '9', '9'};
	char z[5] = {'0', '0', '0', '7'};
	
	printf("z : %s\n", z);
	trim(z);
	printf("Trimmed z : %s\n", z);
	//printf("Check : %s\n", powerOfTen(sub(sub(x, y), z), 3));
	*/

	/*
	char* x = add(a, b);
	trim(x);
	//for(k = 0; k < strlen(x); k++)
	//	printf("(x[%d] : %c) \n", k, x[k]);//db
	printf("Addition : %s\n", x);
	*/
	
	/*
	//trim(x);
	//for(k = 0; k < strlen(x); k++)
	//	printf("(x[%d] : %c) \n", k, x[k]);//db
	trim(x);
	printf("Subtraction : %s\n", x);	
	*/
	
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
	/*
	for(i = 0; i < l; i++)
	{
		a[i] = tempA[i];
		b[i] = tempB[i];
	}
	*/
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
	//printf("a1 : %s\n", a1);//db
	//printf("a2 : %s\n", a2);//db
	
	x = split_at(b, m2);
	b1 = x[0];
	b2 = x[1];
	//printf("b1 : %s\n", b1);//db
	//printf("b2 : %s\n", b2);//db
	
	prependZeroes(a1, a2);
	prependZeroes(b1, b2);
	a3 = add(a1, a2);
	b3 = add(b1, b2);
	trim(a3);
	trim(b3);
	
	l1 = strlen(a3);	
	l2 = strlen(b3);
	//printf("a3 before prepending : %s\n", a3);//db
	//printf("b3 before prepending : %s\n", b3);//db
	l1 > l2 ? (l = l1) : (l = l2);

	z = ceil(log2(l));
	prependZeroes(a3, b3);
	
	//printf("a3 after prepending : %s\n", a3);//db
	//printf("b3 after prepending : %s\n", b3);//db
	
	p1 = karatsubaMultiply(a1, b1, k - 1);
	p2 = karatsubaMultiply(a2, b2, k - 1);
	p3 = karatsubaMultiply(a3, b3, z);
	printf("p1 : %s\n", p1);//db
	printf("p2 : %s\n", p2);//db
	printf("p3 : %s\n", p3);//db
	
	//res1
	res1 = powerOfTen(p1, m);
	
	//res2
	prependZeroes(p3, p1);
	temp = sub(p3, p1);
	//printf("p3 - p1 : %s\n", temp);//db
	prependZeroes(temp, p2);
	//printf("temp : %s\n", temp);//db
	//printf("p2 : %s\n", p2);//db
	temp = sub(temp, p2);
	trim(temp);
	//printf("temp - p2 : %s\n", w);//db
	res2 = powerOfTen(temp, m2);
	//printf("p3 - p1 - p2 : %s\n", res2);//db
	
	//res3
	res3 = p2;
	//res3 = malloc(sizeof(char) * strlen(p2));//db
	//strcpy(res3, p2);
	
	trim(res1);
	trim(res2);
	trim(res3);
	printf("res1 : %s\n", res1);//db
	printf("res2 : %s\n", res2);//db
	printf("res3 : %s\n", res3);//db
	//final
	prependZeroes(res1, res2);
	//printf("res1 after prepending : %s\n", res1);//db
	//printf("res2 after prepending : %s\n", res2);//db
	temp = add(res1, res2);
	trim(temp);
	//printf("temp before prepending : %s\n", temp);//db
	//printf("res3 before prepending : %s\n", res3);//db
	//printf("res1 + res2 : %s\n", temp);//db
	prependZeroes(temp, res3);
	//printf("temp after prepending : %s\n", temp);
	//printf("res3 after prepending : %s\n", res3);
	final = add(temp, res3);
	trim(final);
	return final;
	//return (p1 * powerOfTen(10, m) + (p3 - p1 - p2) * powerOfTen(10, m2) + p2);
}

void trim(char c[])
{
	int l = strlen(c);
	//printf("Length : %zu\n", strlen(c));//db
	int i, j, k;
	
	j = -1;	//if c = '00', it should be transformed into '0'
	for(i = 0; i < l; i++)
		if(c[i] != '0')
		{
			j = i;
			break;
		}
	//printf("j : %d\n", j);//db
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
		//printf("Temp before copy : %s\n", temp);//db
		strcpy(c, temp);
	}
}
/*
char* add(char a[], char b[])
{
	int i, j, x;
	int l;
	l = strlen(a);
	//printf("Length : %zu\n", strlen(a));//db
	char* c = malloc(sizeof(char) * (l + 2));//db
	char* temp = malloc(sizeof(char) * l);//db
	int carry = 0;
	
	//printf("a[999] : %c\n", a[999]);//db
	
	for(i = l - 1; i >= 0 ; i --)
	{
		
		//if(i == 0)
		//	c[i] = carry + '0';
		
		x = 0;
		
		x = (a[i] - '0') + (b[i] - '0') + carry;
		//printf("x : %d\n", x);//db
	
		if(x > 9)
		{
			carry = x / 10;
			x = x % 10;
		}
		else
			carry = 0;
	
		temp[i] = x + '0';
		
		//printf("(temp[%d] : %c)\n", i, temp[i]);//db
	}
	
	//printf("temp before trimming : %s\n", temp);//db
	//trim(temp);//db
	//printf("temp after trimming : %s\n", temp);//db
	
	c[0] = carry + '0';
	
	j = 0;
	for(i = 1; i < l; i++)
		c[i] = temp[j++];
	
	c[l + 1] = '\0';//db
	
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
*/

char* add(char a[], char b[])
{
	int i, j, x;
	int l;
	l = strlen(a);
	//printf("Length : %zu\n", strlen(a));//db
	char* c = malloc(sizeof(char) * (l + 2));//db
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
			//printf("x : %d\n", x);//db
		
			if(x > 9)
			{
				carry = x / 10;
				x = x % 10;
			}
			else
				carry = 0;
		
			c[i] = x + '0';
		}
		
		//printf("(c[%d] : %c) ", i, c[i]);//db
	}

	c[l + 1] = '\0';//db
	
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
	//printf("l : %d\n", l);//db
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
		
		//printf("x : %d\n", x);//db
	
		c[i] = x + '0';
		
		//printf("c[%d] : %c\n", i, c[i]);//db
	}
	
	char* hack = malloc(sizeof(char) * strlen(c));
	for(i = 0; i < strlen(c); i++)
		hack[i] = i + '0';
	prependZeroes(c, hack);
	//printf("c : %s\n", c);//db
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