#include <stdio.h>

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	int sum = 0;

	while (fgets(line, 1024, file)) {
		for (char * c = line; *c != NULL && *c != '\n'; c++) {
			if (*c >= 'A' && *c <= 'Z') {
				*c = *c + 32;
			}
		}

		printf("%s", line);
	}

	return 0;
}