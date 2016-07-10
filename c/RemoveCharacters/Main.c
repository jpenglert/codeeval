#include <stdio.h>
#include <string.h>

// The first argument is a path to a file. The file contains the source strings
// and the characters that need to be scrubbed. Each source string and characters 
// you need to scrub are delimited by comma.
int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];

	char *src = NULL;
	char *scrub = NULL;
	char answer[1024];

	while (fgets(line, 1024, file)) {
		src = strtok(line, ",");
		scrub = strtok(NULL, " ,\n");

		memset(answer, NULL, 1024);
		for (char *c = line; *c != NULL; ++c) {
			if (strchr(scrub, *c) == NULL) {
				strncat(answer, c, 1);
			}
		}

		printf("%s\n", answer);
	}

	return 0;
}

