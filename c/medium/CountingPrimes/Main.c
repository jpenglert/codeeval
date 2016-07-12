#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Given two integers N and M, count the number of prime numbers between N and M (both inclusive)

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Each line in this file contains two comma separated positive integers. E.g.

2,10
20,30

OUTPUT SAMPLE:

Print out the number of primes between N and M (both inclusive)

4
2
*/

int isPrime(int n) {
   if (n < 2) {
      return 0;
   }
   else if (n == 2 || n == 3) {
      return 1;
   }


   for (int i = 2; i <= floor(sqrt(n)); ++i) {
      if (n % i == 0) {
         return 0;
      }
   }

   return 1;
}

void printNumPrimes(int n, int m) {
   int sum = 0;

   for (int i = n; i <= m; ++i) {
      if (isPrime(i)) {
         sum++;
      }
   }

   printf("%d", sum);
}

int main(int argc, const char * argv[]) {
   FILE *file = fopen(argv[1], "r");
   char line[1024];
   int n = 0;
   int m = 0;

   while (fgets(line, 1024, file)) {
      if (line[0] == '\n') {
         continue;
      }

      n = atoi(strtok(line, ",\n"));
      m = atoi(strtok(NULL, ",\n"));

      printNumPrimes(n, m);

      printf("\n");
   }

   return 0;
}

