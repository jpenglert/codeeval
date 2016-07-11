#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your program should accept as its first argument a path to a filename containing 
// decimal numbers greater or equal to 0, one per line.
// Ignore all empty lines.

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	char *str = NULL;
	int n = 0;
	int bit = 0;
	int outputZeros = 0;

	while (fgets(line, 1024, file)) {
		if (line[0] == '\n') {
			continue;
		}

		n = atoi(line);
		if (n == 0) {
			printf("0\n");
			continue;
		}

		outputZeros = 0;
		for (int i = sizeof(n) * 8 - 1; i >= 0; --i) {
			bit = (n >> i) & 1;
			if (bit = (n >> i) & 1) {
				printf("1", 1);
				outputZeros = 1;
			}
			else if (outputZeros) {
				printf("0");
			}
		}

		printf("\n");
	}

	return 0;
}

