#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char *toString(long);
char * split(char *n,int start,int end);
char* karatsuba(char *n1,char *n2,int p);
int findpow(long n);
char * toString(long n);
char *make_same(char *n,int m);
long max(long n,long m);
char * count_zero(char *n,int size);
char * Add(char *n,char *m);
char * subtract(char *n,char *m,char* o);
char * fillZero(char *n,int k);
char * Trim(char * n);
int main()
{
	char* n1 = malloc(sizeof(char)*((int)pow(2,10)));
	char* n2 = malloc(sizeof(char)*((int)pow(2,10)));
	scanf("%s",n1);
	scanf("%s",n2);
	n1=count_zero(n1,strlen(n1));
	n2=count_zero(n2,strlen(n2));
	if(strlen(n1)>strlen(n2))
		n2=make_same(n2,strlen(n1)-strlen(n2));
	else if(strlen(n1)<strlen(n2))
		n1=make_same(n1,strlen(n2)-strlen(n1));
	
	
	//int p=findpow(strlen(n1));db

	/*
	//db
	int k;
	char* x = Add(n1, n2);
	x = Trim(x);
	
	//for(k = 0; k < strlen(x); k++)
	//	printf("(x[%d] : %c) \n", k, x[k]);//db
	
	printf("Addition : %s\n", x);
	*/
	
	//printf("Product %s\n",karatsuba(n1,n2,p));db
	
	return 0;
}
char *make_same(char *n,int m)
{
	int i;
	int size=strlen(n);
	char * temp=malloc(sizeof(char)*(size+1+m));
	
	for(i=0;i<size;i++)
		temp[i+m]=n[i];
	for(i=0;i<m;i++)
		temp[i]='0';
	temp[size+m]='\0';
	
	return temp;
}

char* karatsuba(char *a,char *b,int p)
{
	if(p==0)
	{
		int n=(a[0]-'0')*(b[0]-'0');
		
		return toString(n);
	}
	int k=pow(2,p);
	int m=k/2;
	char* a1;
	char* a2;
	char* b1;
	char* b2;
	
	a1=split(a,0,m);
	a2=split(a,m,k);
	b1=split(b,0,m);
	b2=split(b,m,k);
	int pow2=findpow(strlen(a1));
	
	char* p1=Trim(karatsuba(a1,b1,pow2));
	char* p2=Trim(karatsuba(a2,b2,pow2));
	
	
	char *n1=Add(a1,a2);
	n1=count_zero(n1,strlen(n1));
	char *n2=Add(b1,b2);
	
	n2=count_zero(n2,strlen(n2));
	if(strlen(n1)>strlen(n2))
		n2=make_same(n2,strlen(n1)-strlen(n2));
	else if(strlen(n1)<strlen(n2))
		n1=make_same(n1,strlen(n2)-strlen(n1));
	int pow1=findpow(strlen(n1));

	char* p3=Trim(karatsuba(n1,n2,pow1));
	int max;
	if (strlen(p1)>strlen(p2))
		if(strlen(p1)>strlen(p3))
			max=strlen(p1);
		else
			max=strlen(p3);
	else if (strlen(p2)> strlen(p3))
		max =strlen(p2);
	else
		max =strlen(p3);
	p1=make_same(p1,max-strlen(p1));
	p2=make_same(p2,max-strlen(p2));
	p3=make_same(p3,max-strlen(p3));
	p1=count_zero(p1,strlen(p1));
	p2=count_zero(p2,strlen(p2));
	p3=count_zero(p3,strlen(p3));
	char *p4= Trim((Add(Add(fillZero(p1,k),fillZero(subtract(p3,p2,p1),m)),p2)));
	
	return p4;
}
char* Trim(char p[])
{
	int i;
	int n = strlen(p);
	for(i = 0;i < n;i++)
	{
		if(p[i] != '0')
			break;
	}
	int num = n-i;
	if(num == 0)
	{
		char* a = malloc(sizeof(char)*2);
		a[0] = '0';
		a[1] = '\0';
		return a;
	}
	int k;
	char* r = malloc(sizeof(char)*(num+1));
	for(k = 0;k < num;k++)
	{
		r[k] = p[i++];
	}
	r[k] = '\0';
	return r;
}

char* subtract(char p[],char q[],char r[])
{
	long i;
	int e = strlen(p);
	char* z = malloc(sizeof(char)*e);
	for(i = e-1;i >=0;i--)
	{
		int difference = (p[i] - '0') - (q[i] - '0');
		if(difference < 0)
		{
			int count = i-1;
			while(p[count] == 0)
			{
				count += 1;
			}
			p[count] = p[count] - 1;
			int borrow;
			for(borrow = count + 1;borrow < i;borrow++)
				p[borrow] = 9;
			
			difference += 10;
		}
		z[i] = difference + '0';
	}
	char* z1 = malloc(sizeof(char)*e);
	for(i = e-1;i >=0;i--)
	{
		int difference = (z[i] - '0') - (r[i] - '0');
		if(difference < 0)
		{
			int count = i-1;
			while(z[count] == 0)
			{
				count += 1;
			}
			z[count] = z[count] - 1;
			int borrow;
			for(borrow = count + 1;borrow < i;borrow++)
				z[borrow] = 9;
			
			difference += 10;
		}

		z1[i] = difference + '0';
	}
	z1 = Trim(z1);
	return z1;
}
char * fillZero(char *n,int k)
{
	char * temp=malloc(sizeof(char)*(strlen(n)+k+1));
	int i;
	int size=strlen(n);
	for(i=0;i<size;i++)
		temp[i]=n[i];
	for(;i<size+k;i++)
		temp[i]='0';
		temp[size+k]='\0';
	return temp;
}

char * Add(char *n,char *m)
{
	
	int l1,l2,len,carry=0,i;
	l1=strlen(n);
	l2=strlen(m);
	if(l1>l2)
		len=l1;
	else
		len=l2;
	n=make_same(n,len-l1);
	m=make_same(m,len-l2);
	
	//printf("Length : %zu\n", strlen(n));//db
	char * temp=malloc(sizeof(char)*(len+1));
	for(i=len-1;i>=0;i--)
	{
		int t= (n[i]-'0') + (m[i]-'0') + carry;
		if(t>=9)
		{
			int l=t%10;
			temp[i]=l+48;
			carry=t/10;
		}
		else 
		{	
			temp[i]=t+48;
			carry=0;
		}
	}
	temp[len]='\0';
	char *temp1;
	if(carry!=0)
	{
		temp1=malloc(sizeof(char)*(len+2));
		for(i=0;i<=len;i++)
			temp1[i+1]=temp[i];
		temp1[0]=carry+48;
		free(temp);
		temp=temp1;
	}	
	temp=count_zero(temp,strlen(temp));
	
	return temp;

}

char * count_zero(char *n,int size)
{
	int count=0,m;
	m=pow(2,count);
	while((m=pow(2,count))<size)
	{
		count+=1;

	}
	int noofzero=m-size;

	return make_same(n,noofzero);
}
	

long max(long n,long m)
{
	if(n>m)
		return n;
	else
		return m;
}
char * split(char *n,int start,int end)
{
	int diff=(end-start);
	char *temp=malloc(sizeof(char)*diff);
	int i,j;
	for(i=start,j=0;i<end;i++,j++)
	{	
		temp[j]=n[i];
	}
	return temp;
}
char * toString(long n)
{
	char *p;
	if(n>0)
	{
		int reverse=0;
		int n1=n;
		int count=0,i;
		while(n1!=0)
		{
			reverse=reverse*10;
			reverse+=n1%10;
			n1=n1/10;
			count++;
		}
		p=malloc(sizeof(char)*(count+1));
		for(i=0;i<count;i++)
		{
			p[i]=reverse%10+48;
			reverse/=10;
		}
		p[count]='\0';
		
	}
	else
	{
		p=malloc(sizeof(char)*2);
		p[0]='0';
		p[1]='\0';
	}

	return p;
}

int findpow(long n)
{
	int count=0;
	while(n%2==0 && n>0)
	{
		n=n/2;
		count++;
	}
	return count;
}

