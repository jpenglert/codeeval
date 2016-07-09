#include <stdio.h>
#include <stdlib.h>

// Write a program which determines the number of 1 bits in the internal representation of a given integer.
int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	char *end;
	int i;
	int test;
	int bits ;

	while (fgets(line, 1024, file)) {
		bits = 0;
		i = strtol(line, &end, 10);
		for (int ndx = 0; ndx < 32; ndx++) {
			test = ((i >> ndx) & 1);
			if (test == 1) {
				bits++;
			}
		}
		
		printf("%d\n", bits);
	}

	return 0;
}

