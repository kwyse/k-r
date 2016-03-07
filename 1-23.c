// 1.23 : Remove comments

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getstr(char* filename) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Could not open file '%s'\n", filename);
    exit(EXIT_FAILURE);
  }

  const size_t INITIAL_CAPACITY = 512;
  size_t current_capacity = INITIAL_CAPACITY;
  char* str = malloc(sizeof(char) * INITIAL_CAPACITY);
  
  size_t i = 0;
  int c;
  while ((c = getc(file)) != EOF) {
    str[i++] = c;
    if ((i + 1) >= current_capacity) {
      current_capacity *= 2;
      str = realloc(str, sizeof(char) * current_capacity);
    }
  }

  str[i] = '\0';
  return str;
}

void remove_comments(char str[]) {
  bool in_squote = false;
  bool in_dquote = false;
  bool in_cblock = false;

  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\\') {
      i++;
      continue;
    }

    if (str[i] == '\'' && !in_dquote) {
      in_squote = !in_squote;
      continue;
    }

    if (str[i] == '\"' && !in_squote) {
      in_dquote = !in_dquote;
      continue;
    }

    if (str[i] == '/' && str[i + 1] == '*' && !in_squote && !in_dquote)
      in_cblock = true;

    if (str[i] == '*' && str[i + 1] == '/' && !in_squote && !in_dquote) {
      in_cblock = false;
      if (!in_squote && !in_dquote) {
	memmove(str + i, str + i + 2, strlen(str + i + 2) + 1);
	i--;
      }
    }

    if (in_cblock && !in_squote && !in_dquote) {
      memmove(str + i, str + i + 1, strlen(str + i + 1) + 2);
      i--;
    }

    /* Another comment */
  }
}

int main() {
  char* input = getstr("1-23.c");
  char str[strlen(input)];
  strcpy(str, input);
  free(input);

  puts("A comment that is /* in quotes */ will not be removed");

  remove_comments(str);
  puts(str);

  /* This comment with be removed */

  return EXIT_SUCCESS;
}
