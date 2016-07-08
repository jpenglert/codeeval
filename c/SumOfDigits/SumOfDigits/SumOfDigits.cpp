#include <stdio.h>

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	int sum = 0;

	while (fgets(line, 1024, file)) {
		for (char *cptr = line; *cptr != NULL && *cptr != '\n'; cptr++) {
			sum += (*cptr - '0');
		}
		printf("%d\n", sum);
		sum = 0;
	}

	return 0;
}

