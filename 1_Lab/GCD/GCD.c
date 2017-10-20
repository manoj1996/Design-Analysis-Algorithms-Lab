//***		use ./a.out < input.txt > output.txt
#include<stdio.h>
#include<time.h>

int gcd(int m, int n);
double timeElapsed(struct timespec start, struct timespec end);

int main()
{
	int tc;
	int m, n;
	
	struct timespec start, end;
		
	scanf("%d", &tc);
	
	clock_gettime(CLOCK_REALTIME, &start);
	
	while(tc--)
	{
		//***
		scanf("%d%d", &m, &n);	//takes two integers separated by whitespace or blank line (from input.txt) in each iteration of the loop
		printf("%d\n", gcd(m, n));	//prints the GCD of the above two numbers into output.txt
	}
	clock_gettime(CLOCK_REALTIME, &end);
	
	printf("Execution time : %lf milliseconds\n", timeElapsed(start, end));
	return 0;
}

int gcd(int m, int n)
{
	int r;
	
	while(n)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

double timeElapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	return t;
}
