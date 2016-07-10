#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Write a program which prints all the permutations of a string in alphabetical order.
// We consider that digits < upper case letters < lower case letters.
// The sorting should be performed in ascending order.

struct tree {
	char *str;
	struct tree *left;
	struct tree *right;
};

struct tree* createNode() {
	struct tree *t = malloc(sizeof(struct tree));
	(*t).str = NULL;
	(*t).left = NULL;
	(*t).right = NULL;

	return t;
}

void add(struct tree *t, char *str) {
	if ((*t).str == NULL) {
		(*t).str = malloc(sizeof(char) * strlen(str) + 1);
		memset((*t).str, NULL, strlen(str) + 1);
		strcpy((*t).str, str);
	}
	else {
		if (strcmp(str, (*t).str) < 0) {
			if ((*t).left == NULL) {
				(*t).left = createNode();
			}
			add((*t).left, str);
		}
		else {
			if ((*t).right == NULL) {
				(*t).right = createNode();
			}
			add((*t).right, str);
		}
	}
}

void printTree(struct tree *t, char *outline) {
	if (t == NULL) {
		return;
	}

	printTree((*t).left, outline);
	strcat(outline, (*t).str);
	strcat(outline, ",");
	printTree((*t).right, outline);
}

void deleteTree(struct tree *t) {
	if (t == NULL) {
		return;
	}

	deleteTree((*t).left);
	deleteTree((*t).right);

	if ((*t).str == NULL) {
		free((*t).str);
		(*t).str = NULL;
	}
	(*t).left = NULL;
	(*t).right = NULL;
	free(t);
}

void doPermutation(char *str, char *permutation, char *used, int length, struct tree *t) {

	if (strlen(permutation) == length) {
		add(t, permutation);
		return;
	}

	for (int i = 0; i < length; i++) {
		if (used[i]) {
			continue;
		}

		strncat(permutation, str + i, 1);
		used[i] = 1;
		doPermutation(str, permutation, used, length, t);
		used[i] = 0;
		permutation[strlen(permutation) - 1] = NULL;
	}
}

void trim(char *str) {
	for (char *c = str; *c != NULL; c++) {
		if (*c == '\n' || *c == '\r' || *c == ' ') {
			*c = NULL;
			break;
		}
	}
}

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	char outline[1024];
	int length = 0;
	char *permutation = NULL;
	char *used = NULL;
	struct tree *t = NULL;

	while (fgets(line, 1024, file)) {
		trim(line);
		length = strlen(line);
		permutation = malloc(sizeof(char) * (length + 1));
		used = malloc(sizeof(char) * length);
		memset(permutation, NULL, length + 1);
		memset(used, 0, length);
		t = createNode();

		doPermutation(line, permutation, used, length, t);

		memset(outline, NULL, 1024);
		printTree(t, outline);
		outline[strlen(outline) - 1] = NULL;
		printf("%s\n", outline);

		deleteTree(t);
		free(permutation);
		free(used);
	}

	return 0;
}

