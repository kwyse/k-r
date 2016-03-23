// header.h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Debug a pointer to char
#define dbp(x) { printf("Value of %s: %p (%c)\n", #x, x, *x); }

// Assertions
#define a(exp) { printf("%s | %s\n", exp ? "(/) Success" : "(x) FAILURE", #exp); }
#define as(s1, s2) { printf("%s | %s == %s\n", \
			    (strcmp(s1, s2) == 0) ? "(/) Success" : "(x) FAILURE", #s1, #s2); }

void putd(int d);
void putf(double f);
size_t getlnlen(char* line);
void reverse(char str[]);

// Prints a signed integer to stdout
void putd(int d) {
  printf("%d\n", d);
}

// Prints a double to stdout
void putf(double f) {
  printf("%g\n", f);
}

// Returns the length of a line of characters
size_t getlnlen(char* line) {
  size_t i;
  for (i = 0; line[i] != '\n' && line[i] != '\0'; i++);
  return i;
}

// Reverses a string in place
void reverse(char str[]) {
  size_t len = getlnlen(str);
  for (size_t i = 0, j = len - 1; (i < (len / 2)) && (j >= (len / 2)); i++, j--) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}
