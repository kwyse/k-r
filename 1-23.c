// 1.23 : Remove comments

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rmsubstr(char str[], size_t start, size_t end);

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
    
    if (str[i] == '\'' && !in_dquote)
      in_squote = !in_squote;

    if (str[i] == '\"' && !in_squote)
      in_dquote = !in_dquote;

    if (str[i] == '/' && str[i + 1] == '*')
      in_cblock = true;

    if (str[i] == '*' && str[i + 1] == '/') {
      in_cblock = false;
      memmove(str + i, str + i + 2, strlen(str + i + 2) + 1);
    }

    if (in_cblock && !in_squote && !in_dquote) {
      memmove(str + i, str + i + 1, strlen(str + i + 1) + 1);
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

  remove_comments(str);
  puts(str);

  /* This comment with be removed */

  return EXIT_SUCCESS;
}
