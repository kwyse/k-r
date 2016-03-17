// 3.5 : itob

#include <math.h>
#include "header.h"

void itob(int n, char s[], int b);

void itob(int n, char s[], int b) {
  bool isneg = n < 0;
  if (isneg)
    n = -(n + 1);

  size_t i = 0;
  int first = (n % b) + (isneg ? 1 : 0);
  s[i++] = first + (first > 9 ? 'A' - 10 : '0');
  while ((n /= b) > 0)
    s[i++] = (n % b) + ((n % b) > 9 ? 'A' - 10: '0');

  if (isneg)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

int main() {
  char output[100];
  itob(14, output, 8);
  puts(output);
  itob(14, output, 10);
  puts(output);
  itob(14, output, 16);
  puts(output);
  itob(251, output, 16);
  puts(output);

  return 0;
}
