// strpbrk called any

#include <string.h>
#include <stdio.h>

// like strchr
int strfnd(const char* str, char c) {
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == c)
      return i;
  }

  return -1;
}

int any(const char* s1, const char* s2) {
  int min = strlen(s1);
  
  for (size_t i = 0; s1[i] != '\0'; i++) {
    if (strfnd(s2, s1[i]) > -1) {
      if (i < min)
	min = i;
    }
  }

  if (min == strlen(s1))
    return -1;
  else
    return min;
}

int main() {
  char* input = "hey there, friend";
  printf("\"%s\" %d\n", input, any(input, "te"));
  return 0;
}
