#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
PRIME NUMBERS
CHALLENGE DESCRIPTION:

Print out the prime numbers less than a given number N. For bonus points your solution should run in N*(log(N)) time or better. You may assume that N is always a positive integer.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Each line in this file is one test case. Each test case will contain an integer n < 4,294,967,295. E.g.

10
20
100
OUTPUT SAMPLE:

For each line of input, print out the prime numbers less than N, in ascending order, comma delimited. (There should not be any spaces between the comma and numbers) E.g.

2,3,5,7
2,3,5,7,11,13,17,19
2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
*/

int isPrime(int n) {
	for (int i = 2; i <= floor(sqrt(n)); ++i) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

void printPrimes(int n) {
	if (n > 2) {
		printf("2");
	}

	for (int i = 3; i < n; i += 2) {
		if (isPrime(i)) {
			printf(",%d", i);
		}
	}
}

void printPrimesSieveOfEratosthenes(int n) {
	clock_t start = clock();
	clock_t end;
	double elapsed = 0;

	char *sieve = malloc(sizeof(char) * n);
	memset(sieve, 1, n);

	for (int i = 2; i < floor(sqrt(n)); ++i) {
		if (sieve[i]) {
			for (int j = i * i, k = 0; j < n; j = i * i + ++k * i) {
				sieve[j] = 0;
			}
		}
	}

	if (n > 2) {
		printf("2");
	}

	for (int i = 3; i < n; ++i) {
		if (sieve[i]) {
			printf(",%d", i);
		}
	}

	free(sieve);

	end = clock();
	elapsed = (end - start) / (double)CLOCKS_PER_SEC;
	printf("\n\nTime: %f s", elapsed);
}

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	int n = 0;

	while (fgets(line, 1024, file)) {
		if (line[0] == '\n') {
			continue;
		}

		n = atoi(line);
		printPrimes(n);
		printf("\n");
	}

	return 0;
}

