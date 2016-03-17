// 3.6 : itoa with minimum field width

#include "header.h"

void itob(int n, char s[], size_t minwidth);

void itob(int n, char s[], size_t minwidth) {
  bool isneg = n < 0;
  if (isneg)
    n = -(n + 1);

  size_t i = 0;
  s[i++] = (n % 10) + (isneg ? 1 : 0) + '0';
  while ((n /= 10) > 0)
    s[i++] = (n % 10) + '0';

  if (isneg)
    s[i++] = '-';

  while (i < minwidth)
    s[i++] = ' ';

  s[i] = '\0';
  reverse(s);
}

int main() {
  char output[100];
  itob(14, output, 0);
  puts(output);
  itob(14, output, 1);
  puts(output);
  itob(14, output, 2);
  puts(output);
  itob(14, output, 3);
  puts(output);
  itob(14, output, 4);
  puts(output);
  itob(14, output, 8);
  puts(output);
  itob(-14, output, 8);
  puts(output);

  return 0;
}
