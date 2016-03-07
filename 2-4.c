// 2.4 : Squeeze

#include <string.h>
#include <stdio.h>

void squeeze(char s1[], const char* s2) {
  for (size_t i = 0; i < strlen(s2); i++) {
    size_t k = 0;
    for (size_t j = 0; s1[j] != '\0'; j++) {
      if (s1[j] != s2[i])
	s1[k++] = s1[j];
    }

    s1[k] = '\0';
  }
}

int main() {
  char input[] = "yellow moon";
  squeeze(input, "lo");
  puts(input);

  return 0;
}
