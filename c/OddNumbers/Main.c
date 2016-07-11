#include <stdio.h>

// Print the odd numbers from 1 to 99.
// Print the odd numbers from 1 to 99, one number per line.

int main(int argc, const char * argv[]) {

   for (int n = 1; n <= 99; ++n) {
      if (n % 2 != 0) {
         printf("%d\n", n);
      }
   }

   return 0;
}