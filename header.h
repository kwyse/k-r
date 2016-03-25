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

#include <sys/time.h>
#include <sys/resource.h>
static double gettime(void);

static double gettime(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + (t.tv_usec * 1e-6);
}
	
// Benchmarks a code block
#define bench(b) { double s = gettime(); { b; } double e = gettime(); printf("%fms\n", (e - s) * 1000); }

void putd(int d);
void putf(double f);
size_t getlnlen(char* line);
void reverse(char str[]);
int getln(char* s, int maxlen);
char* alloc(int nbytes);
void afree(char* ptr);

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

int getln(char* s, int maxlen)
{
    int i = 0, c = 0;
    for ( ; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	s[i] = c;

    if (c == '\n') {
	s[i] = c;
	++i;
    }

    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char* allocptr = allocbuf;

// Returns a pointer to allocated bytes
char* alloc(int nbytes)
{
    if (allocbuf + ALLOCSIZE - allocptr >= nbytes) {
	allocptr += nbytes;
	return allocptr - nbytes;
    } else
	return 0;
}

// Deallocates allocated bytes
void afree(char* ptr)
{
    if (ptr >= allocbuf && ptr < allocbuf + ALLOCSIZE)
	allocptr = ptr;
}
