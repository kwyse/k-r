// 2.2 : Waste of time for loop

#include <stdio.h>

int main() {
  int lim = 10;
  int c = getchar();
  for (int i = 0; i < lim - 1; i++) {
    if (c == EOF)
      break;

    if (c == '\n')
      break;

    // do something
  }

  return 0;
}
