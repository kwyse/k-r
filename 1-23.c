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

void strshft(char str[], size_t at) {
  if (at > strlen(str) - 1)
    perror("Index out of bounds");

  memmove(str, str + 1, strlen(str));
}

void remove_comments(char str[]) {
  bool in_squote = false;
  bool in_dquote = false;
  bool in_cblock = false;

  size_t len = strlen(str);
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\\') {
      i++;
      continue;
    }
    
    if (str[i] == '\'' && !in_dquote)
      in_squote = !in_squote;

    if (str[i] == '\"' && !in_squote)
      in_dquote = !in_dquote;

    if (str[i] == '/' && str[i + 1] == '*') {
      in_cblock = true; puts("CB+");}

    if (str[i] == '*' && str[i + 1] == '/') {
      in_cblock = false;
      memmove(str + i, str + i + 3, strlen(str + i + 3) + 1);
      puts("CB-");
    }

    if (in_cblock && !in_squote && !in_dquote) {
      memmove(str + i, str + i + 1, strlen(str + i + 1) + 1);
      i--;
    }

    //* Another commetn */

    //if (in_cblock && !in_squote && !in_dquote)
      //str[i] = '@';
   //strshft(str + i, 1);
      //memmove(&str[i], &str[i + 1], strlen(&str[i]));
      //rmsubstr(str, 14, 20);
    //&(str+i) = memmove(str + i, str + i + 1, strlen(str));
      //rmsubstr(str, strstr(str, "/* comment */"), 13);
      // memmove(strstr(str, "/* comment */"), strstr(str, "/* comment */") + 13, strlen(str) - 26);
    //    len--;
  }
}

void rmsubstr(char str[], size_t start, size_t end) {
  memmove(str + start, str + end, strlen(str) + start);
}

void decomment(char str[]) {
  int start = -1, end = -1;

  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == '/' && str[i + 1] == '*')
      start = i;

    if (str[i] == '*' && str[i + 1] == '/')
      end = i + 2;
  }

  if (start != -1 && end != -1) {
    printf("Removing comment beween indexes %d and %d\n", start, end);
    memmove(str + start, str + end, strlen(str + end) + 1);
  }
}
    //while ((c = getc()) != EOF) 

int main() {
  char* input = getstr("test");
  char str[strlen(input)];
  strcpy(str, input);
  free(input);

  //remove_comments(str);
  puts(str);

  char* s = "This is a very long string";
  char ss[strlen(s)];
  strcpy(ss, s);
  //puts(ss);
  //s = memmove(ss, ss + 6, strlen(ss) - 5);
  puts("VVV");
  //puts(s);
  //strshft(s, 1);
  //memmove(ss + 4, ss + 4 + 3, strlen(ss) - 4 - 3 + 1);
  puts(ss);

  //rmsubstr(ss, 2, 4);
  //decomment(str);
  remove_comments(str);
  puts(str);

  /* This comment with be removed */

  return EXIT_SUCCESS;
}
