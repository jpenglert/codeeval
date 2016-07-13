#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct tree {
   char *str;
   struct tree *left;
   struct tree *right;
};

struct tree* createNode() {
   struct tree *t = malloc(sizeof(struct tree));
   t->str = NULL;
   t->left = NULL;
   t->right = NULL;

   return t;
}

void add(struct tree *t, char *str) {
   int strCmp = 0;

   if (t->str == NULL) {
      t->str = malloc(sizeof(char) * strlen(str) + 1);
      memset(t->str, NULL, strlen(str) + 1);
      strcpy(t->str, str);
   }
   else {
      strCmp = strcmp(str, t->str);
      if (strCmp < 0) {
         if (t->left == NULL) {
            t->left = createNode();
         }
         add(t->left, str);
      }
      else if (strCmp > 0) {
         if (t->right == NULL) {
            t->right = createNode();
         }
         add(t->right, str);
      }
      else {
         // str is a duplicate so drop it
      }
   }
}

void deleteTree(struct tree *t) {
   if (t == NULL) {
      return;
   }

   deleteTree(t->left);
   deleteTree(t->right);

   if (t->str == NULL) {
      free(t->str);
      t->str = NULL;
   }
   t->left = NULL;
   t->right = NULL;
   free(t);
}

static first;

void printTree(struct tree *t, bool *printComma) {
   if (t == NULL || t->str == NULL) {
      return;
   }

   printTree(t->left, printComma);
   if (*printComma) {
      printf(",");
   }
   printf("%s", t->str);
   *printComma = true;
   printTree(t->right, printComma);
}

void findUniqueChars(char *in, char *out) {
   bool chars[256] = { false };

   for (char *c = in; *c != NULL; ++c) {
      if (!chars[*c]) {
         strncat(out, c, 1);
         chars[*c] = true;
      }
   }
}

void doPermutation(char *letters, char *out, int n, struct tree *t) {
   if (strlen(out) == n) {
      add(t, out);
      return;
   }

   for (char *c = letters; *c != NULL; ++c) {
      strncat(out, c, 1);
      doPermutation(letters, out, n, t);
      out[strlen(out) - 1] = NULL;
   }
}

void solve(int n, char *s) {
   struct tree *t = createNode();
   char letters[1024] = { NULL };
   char out[1024] = { NULL };
   bool printComma = false;
   
   findUniqueChars(s, letters);
   doPermutation(letters, out, n, t);
   printTree(t, &printComma);
   
   printf("\n");
}

int main(int argc, const char * argv[]) {
   FILE *file = fopen(argv[1], "r");
   char line[1024];
   int n = 0;
   char *s = NULL;

   while (fgets(line, 1024, file)) {
      n = atoi(strtok(line, ","));
      s = strtok(NULL, "\n");
      solve(n, s);
   }

   return 0;
}