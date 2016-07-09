#include <stdio.h>

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	char *end;
	int answer = 0;

	while (fgets(line, 1024, file)) {
		answer += strtol(line, &end, 10);
	}

	printf("%d", answer);

	return 0;
}