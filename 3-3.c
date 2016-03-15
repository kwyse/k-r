// 3.3 : Expand character and number ranges

#include <ctype.h>
#include "header.h"

void expand(const char* s1, char s2[]);

void expand(const char* s1, char s2[]) {
  size_t j = 0;
  for (size_t i = 0; i < strlen(s1); i++, j++) {
    if (s1[i] == '-') {
      if (isupper(s1[i - 1]) && isupper(s1[i + 1])) {
	char c = s1[i - 1];
	for (j = j - 1; c < s1[i + 1] + 1; j++, c++) {
	  s2[j] = c;
	}

	i++;
      }
    }
  }

  s2[j] = '\0';
}

int main() {
  char* input = "A-G";
  char output[100];

  expand(input, output);
  puts(output);

  return 0;
}
