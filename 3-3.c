// 3.3 : Expand character and number ranges

#include <ctype.h>
#include "header.h"

void expand(const char* s1, char s2[]);

void expand(const char* s1, char s2[]) {
  size_t i = 0, j = 0;
  if (s1[0] == '-')
    s2[j++] = s1[i++];

  while (s1[i] != '\0') {
    if (s1[i] == '-') {

      if ((isupper(s1[i - 1]) && isupper(s1[i + 1])) ||
	  (islower(s1[i - 1]) && islower(s1[i + 1])) ||
	  (isdigit(s1[i - 1]) && isdigit(s1[i + 1]))) {
	char c = s2[--j];
	const char end = s1[++i];
	while (c < end)
	  s2[j++] = c++;

	continue;
      }
    }

    s2[j++] = s1[i++];
  }

  s2[j] = '\0';
}

int main() {
  char* input = "-A-G- k-w -A-Zb-i-p1-9-";
  char output[100];

  expand(input, output);
  puts(output);

  return 0;
}
