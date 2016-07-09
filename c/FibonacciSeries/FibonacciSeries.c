#include <stdio.h>
#include <stdlib.h>

int find(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}

	return find(n - 1) + find(n - 2);
}

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	char *end;
	int n;
	int answer;

	while (fgets(line, 1024, file)) {
		n = strtol(line, &end, 10);
		answer = find(n);
		printf("%d\n", answer);
	}

	return 0;
}