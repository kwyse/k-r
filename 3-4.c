// 3.4 : itoa

#include "header.h"

void itoa(int n, char s[]);

void itoa(int n, char s[]) {
  int sign = n;
  if (n < 0)
    n = -n;

  int i = 0;
  do
    s[i++] = (n % 10) + '0';
  while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

int main() {
  char output[100];
  itoa(-3344, output);
  puts(output);
  itoa(-2147483647, output);
  puts(output);
  itoa(-2147483648, output);
  puts(output);

  return 0;
}
