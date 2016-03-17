// 3.4 : itoa

#include <math.h>
#include "header.h"

void itoa(int n, char s[]);

void itoa(int n, char s[]) {
  bool isneg = n < 0;
  if (isneg)
    n = -(n + 1);

  size_t i = 0;
  s[i++] = (n % 10) + (isneg ? 1 : 0) + '0';
  while ((n /= 10) > 0)
    s[i++] = (n % 10) + '0';

  if (isneg)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

int main() {
  char output[100];
  itoa(-8, output);
  puts(output);
  itoa(-3344, output);
  puts(output);
  itoa(-2147483647, output);
  puts(output);
  itoa(2147483647, output);
  puts(output);
  itoa(-2147483648, output);
  puts(output);
  itoa(0, output);
  puts(output);
  itoa(1, output);
  puts(output);
  itoa(-1, output);
  puts(output);
  itoa(-21, output);
  puts(output);

  return 0;
}
