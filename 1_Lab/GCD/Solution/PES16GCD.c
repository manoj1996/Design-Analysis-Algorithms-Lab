//DAA Lab Sample Exercise for Week 1
//Finding gcd of two nonnegative integers 

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 	//needed for clock_gettime()
					//Linker needs library -lrt

//Function declarations
//Finds gcd of nonnegative integers m and n
int gcd(int m, int n);
//Finds time elapsed from start to end in milliseconds
double time_elapsed(struct timespec start, struct timespec end);

int main(void) {
	int tc; //test cases count
	int m, n; //gcd of m and n to be found
	struct timespec start, end; //timestamps
	
	scanf("%d", &tc);
	clock_gettime(CLOCK_REALTIME, &start); //Start time noted
	while(tc--) {
		scanf("%d%d", &m, &n);
		printf("%d\n", gcd(m, n));
	}
	clock_gettime(CLOCK_REALTIME, &end); //End time noted
	printf("Execution time: %.6lf millisec.\n", time_elapsed(start, end));
	return 0;
}

//Time elapsed from 'start' to 'end' in milliseconds
double time_elapsed(struct timespec start, struct timespec end) {
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000; //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000001; //add diff of tv_nsec too
	return t;
}

//Finds gcd of nonnegative integers m and n
int gcd(int m, int n) {
	int r;

	//gcd(m, 0) = m
	while (n != 0) {
		//gcd(m, n) = gcd(n, m mod n)
		r = m % n; //n <-- m mod n 
		m = n; //m <-- n
		n = r; 
	}
	return m;
}
