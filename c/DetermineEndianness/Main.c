#include <stdio.h>

// Write a program which prints the endianness of the system.
int main(int argc, const char * argv[]) {
	int i = 1;
	char *c = &i;
	if (*c == 1) {
		printf("LittleEndian");
	}
	else {
		printf("BigEndian");
	}

	return 0;
}