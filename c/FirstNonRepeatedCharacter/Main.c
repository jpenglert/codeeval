#include <stdio.h>

// Write a program which finds the first non-repeated character in a string.
int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	int ascii[128];
	
	while (fgets(line, 1024, file)) {
		for (int i = 0; i < 128; i++) {
			ascii[i] = 0;
		}

		for (char *c = line; *c != NULL && *c != '\n'; c++) {
			ascii[*c] += 1;
		}

		for (char *c = line; *c != NULL && *c != '\n'; c++) {
			if (ascii[*c] == 1) {
				printf("%c\n", *c);
				break;
			}
		}
	}

	return 0;
}